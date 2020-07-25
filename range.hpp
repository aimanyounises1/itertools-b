

#ifndef _RANGE_HPP_
#define _RANGE_HPP_
namespace itertools{
    class range{
        int _begin, _end;

    public:
        range(int begin, int end): _begin(begin), _end(end){}
    typedef  int value_type;
        class iterator{
            int _data;
        public:
            explicit iterator(int d): _data(d) {};
            iterator& operator=(const iterator& other){
                if(this != &other)
                    this->_data = other._data;
                return *this;
            };
            iterator& operator ++(){
                ++_data;
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++_data;
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return (_data == other._data);
            }
            bool operator !=(const iterator& other) {
                return (_data != other._data);
            }
            int operator *(){
                return _data;
            }
        };

        iterator begin(){
            return iterator(_begin);
        }
        iterator end(){
            return iterator(_end);
        }


    };
}
#endif