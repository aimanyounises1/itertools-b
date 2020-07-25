#ifndef ACCUMULATE_HPP
#define ACCUMULATE_HPP
   namespace itertools{
    typedef struct{
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } plus;

    template <typename C, typename  Functor = plus>
    class accumulate{
        Functor func;
   
            C cont;
 public:
        explicit accumulate(C cont, Functor func = plus())
                : cont(cont), func(func){}

        class iterator{
            typename C :: value_type data;
           typename  C::iterator it;
                      typename  C::iterator end;

            Functor function;
        public:
                explicit iterator ( typename  C::iterator it,typename  C::iterator end, Functor f)    : it(it),end(end) , function(f), data(*it){};
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
            iterator& operator ++(){
                ++it;
                if(it != end)
                    data = function(data, *it);
                return *this;
            }
            iterator operator ++(int){
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