#ifndef ACCUMULATE_HPP
#define ACCUMULATE_HPP
   namespace itertools{
       //functor plus
    class plus  {
        public:
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } ;

    template <typename Container, typename  Functor = plus>
    class accumulate{
        Functor func;
        Container cont;
 public:
 // recieves functor and container
        explicit accumulate(Container cont, Functor func = plus{})
                : cont(cont), func(func){}

        class iterator{
            typename Container :: value_type data;
            typename  Container::iterator it;// begin
            typename  Container::iterator end;
            Functor function;
        public:
 explicit iterator ( typename  Container::iterator it,typename Container::iterator end, Functor f)
                    : it(it),end(end) , function(f), data(*it){};
            iterator(const iterator& other) = default;
            iterator& operator=(const iterator& other){
                if(this != &other) {
                    this->data = other.data;
                    this->it = other.it;
                    this->end = other.end;
                    this->function = other.function;
                }
                return *this;
            };
            //postfix
            iterator& operator++(){
                ++it;
                if(it != end)
                // adding the elements and updating it in example 5+6 = 11 so the data is 11 now
                    data = function(data, *it);
                return *this;
            }
            //prefix 
            iterator operator++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return (it == other.it);
            }
            bool operator !=(const iterator& other) {
                return (it != other.it);
            }
            // return the data
            auto operator *(){
                return data;
            }
        };


        iterator begin(){
            return iterator(cont.begin(),cont.end(), func);
        }
        iterator end(){
            return iterator(cont.end(),cont.end(), func);
        }

    };
}
#endif