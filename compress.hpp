#ifndef COMPRESS_HPP
#define COMPRESS_HPP
#include <iostream>
#include <vector>
namespace itertools
{
    template<typename cont , typename contbool> class compress
    {
        cont c;
        contbool c2;
        public:
         explicit compress ( cont c, contbool c2) : c(c),c2(c2){
            typename cont::iterator it= c.begin();
            typename contbool::iterator it2= c2.begin();
           int c1=0; int c3=0;
           while(it!=c.end())
           {
               ++it;
               c1++;
           }
             while(it2!=c2.end())
           {
               ++it2;
               c3++;
           }
           
           if(c1!=c3)
           throw std::invalid_argument ("containers must be same size");
           
    }
    
      class iterator{
         typename cont :: iterator it;
         typename cont :: iterator end;
         typename contbool :: iterator it2;
         public:
         iterator(typename cont :: iterator it,  typename cont :: iterator end,  typename contbool :: iterator it2) : it(it), end(end), it2(it2){
             while( it!=end&&!(*it2))
             {
                 ++it;
                 ++it2;
             }
         }
         
         bool operator == (const iterator& other)
         {
             return (it==other.it);
         }
         
         bool operator != (const iterator& other)
         {
             return (it!=other.it);
         }
         
         iterator& operator = (const iterator& other)
         {
             it=other.it;
             end=other.end;
             it2=other.it2;
         }
         
         iterator& operator ++()
         {
             do
             {
             ++it;
             ++it2;
             }
             while(it!=end&&!(*it2));
            
             return *this;
         }
         
         iterator& operator ++(int)
         {
            iterator tmp=*this;
            ++(*this);
            return tmp;
         }
         
          
         auto operator *()
         {return *it;
         }
      };
    iterator begin()
    {
        return iterator(c.begin(),c.end(),c2.begin());
    }
    iterator end()
    {
        return iterator(c.end(),c.end(),c2.end());
    }
};
}
#endif
