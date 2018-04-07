
#ifndef BOOST_QVM_VEC_REGISTER3_HPP
#define BOOST_QVM_VEC_REGISTER3_HPP

#include <boost/qvm/detail/vec_register_impl.hpp>

#define BOOST_QVM_REGISTER_VEC_3_READ(VecType, ScalarType, Read0, Read1, Read2)             \
BOOST_QVM_DETAIL_REGISTER_VEC_SPECIALIZE_VEC_TRAITS_READ(VecType, ScalarType, 3)            \
BOOST_QVM_DETAIL_SPECIALIZE_QVM_DETAIL_VEC_REGISTER_READ(VecType, ScalarType, 3, 0, Read0)  \
BOOST_QVM_DETAIL_SPECIALIZE_QVM_DETAIL_VEC_REGISTER_READ(VecType, ScalarType, 3, 1, Read1)  \
BOOST_QVM_DETAIL_SPECIALIZE_QVM_DETAIL_VEC_REGISTER_READ(VecType, ScalarType, 3, 2, Read2)

#define BOOST_QVM_REGISTER_VEC_3_READ_WRITE(VecType, ScalarType, Read0, Read1, Read2, Write0, Write1, Write2)   \
BOOST_QVM_DETAIL_REGISTER_VEC_SPECIALIZE_VEC_TRAITS_READ_WRITE(VecType, ScalarType, 3)                          \
BOOST_QVM_DETAIL_SPECIALIZE_QVM_DETAIL_VEC_REGISTER_READ_WRITE(VecType, ScalarType, 3, 0, Read0, Write0)        \
BOOST_QVM_DETAIL_SPECIALIZE_QVM_DETAIL_VEC_REGISTER_READ_WRITE(VecType, ScalarType, 3, 1, Read1, Write1)        \
BOOST_QVM_DETAIL_SPECIALIZE_QVM_DETAIL_VEC_REGISTER_READ_WRITE(VecType, ScalarType, 3, 2, Read2, Write2)

#define BOOST_QVM_REGISTER_VEC_3(VecType, ScalarType, Element0, Element1, Element2)   \
BOOST_QVM_REGISTER_VEC_3_READ_WRITE(VecType, ScalarType, Element0, Element1, Element2, Element0, Element1, Element2)

#endif
