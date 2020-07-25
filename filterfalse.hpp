//
// Created by nati on 08/06/2020.
//

#ifndef CPPEX5_ITERTOOLS_FILTERFALSE_HPP
#define CPPEX5_ITERTOOLS_FILTERFALSE_HPP

#include <iostream>
#include <vector>

namespace itertools{
    template<typename FUNC, typename CONT>
    class filterfalse {
        FUNC _f;
        CONT& _container;
        typedef typename CONT::value_type value_type;

    public:
        filterfalse(FUNC f, CONT& container): _f(f), _container(container){}

        class iterator{
            typename CONT::iterator _iter;
            typename CONT::iterator _end;
            FUNC _f;
        public:
            explicit iterator(typename CONT::iterator iter, typename CONT::iterator end, FUNC f)
                : _iter(iter), _end(end), _f(f){

                while (_iter != _end && _f(*_iter))
                    ++_iter;
            }
            iterator(const iterator& other) = default;

            iterator& operator=(const iterator& other){
                if(this != &other) {
                    this->_iter = other._iter;
                    this->_end = other._end;
                    this->_f = other._f;
                }
                return *this;
            };
            iterator& operator ++(){
                do{
                    ++_iter;
                } while (_iter != _end && _f(*_iter));
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return (_iter == other._iter);
            }
            bool operator !=(const iterator& other) {
                return (_iter != other._iter);
            }
            value_type operator *(){
                return *_iter;
            }

        };
        iterator begin(){
            return iterator(_container.begin(), _container.end(), _f);
        }
        iterator end(){
            return iterator(_container.end(), _container.end(), _f);
        }
    };
}
#endif //CPPEX5_ITERTOOLS_FILTERFALSE_HPP