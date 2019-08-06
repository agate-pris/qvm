//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/vec_access.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include "test_qvm_vector.hpp"
#include <cmath>

using namespace boost::qvm;

template <int I>
void
check_idx( test_qvm::vector<V1,10> & v, float & (*f)( test_qvm::vector<V1,10> & ) )
    {
    BOOST_TEST((&A<I>(v)==&v.a[I]));
    BOOST_TEST((&f(v)==&v.a[I]));
    }

template <int I,int D>
struct check_get_detail
    {
    template <class V>
    static void f(
        V const & v,
        typename boost::qvm::vec_traits<V>::scalar_type const & start,
        typename boost::qvm::vec_traits<V>::scalar_type const & step )
        {
        BOOST_TEST(std::abs(boost::qvm::get<I>(v)-start-step*I)<0.001);
        check_get_detail<I+1,D>::f(v,start,step);
        }
    };

template <int D>
struct check_get_detail<D,D>
    {
    template <class V>
    static void f(
        V const &,
        typename boost::qvm::vec_traits<V>::scalar_type const &,
        typename boost::qvm::vec_traits<V>::scalar_type const & ) {}
    };

template <class S,int D>
void check_get()
    {
    boost::random::mt19937_64 e(0);
    boost::random::uniform_real_distribution<S> d(S(100.0),S(200.0));
    S const start = d(e);
    S const step = d(e);
    test_qvm::vector<V1,D,S> const v(start,step);
    check_get_detail<0,D>::f(v,start,step);
    }

template <int I,int Dim>
struct check_set_detail
    {
    template <class V,class E,class D>
    static void f( V & v, E & e, D & d )
        {
        boost::qvm::set<I>(v,d(e));
        check_set_detail<I+1,Dim>::f(v,e,d);
        }
    template <class V,class E,class D>
    static void g( V & v, E & e, D & d )
        {
        BOOST_TEST(boost::qvm::get<I>(v)==d(e));
        check_set_detail<I+1,Dim>::g(v,e,d);
        }
    };

template <int Dim>
struct check_set_detail<Dim, Dim>
    {
    template <class V,class E,class D>
    static void f( V &, E &, D & ) {}
    template <class V,class E,class D>
    static void g( V &, E &, D & ) {}
    };

template <class S, int D>
void check_set()
    {
    boost::random::mt19937_64 e(0);
    boost::random::uniform_real_distribution<S> d(100.0,200.0);
    test_qvm::vector<V1, D, S> v;
    check_set_detail<0,D>::f(v,e,d);
    e.seed(0);
    d.reset();
    check_set_detail<0, D>::g(v,e,d);
    }

int
main()
    {       
    test_qvm::vector<V1,10> v;
#define CHECK_A(i) check_idx<i>(v,A##i);
    CHECK_A(0);
    CHECK_A(1);
    CHECK_A(2);
    CHECK_A(3);
    CHECK_A(4);
    CHECK_A(5);
    CHECK_A(6);
    CHECK_A(7);
    CHECK_A(8);
    CHECK_A(9);
#undef CHECK_A
    BOOST_TEST(&A<0>(v)==&X(v));
    BOOST_TEST(&A<1>(v)==&Y(v));
    BOOST_TEST(&A<2>(v)==&Z(v));
    BOOST_TEST(&A<3>(v)==&W(v));
    check_get<float,1>();
    check_get<float,2>();
    check_get<float,3>();
    check_get<float,4>();
    check_get<float,5>();
    check_get<double,1>();
    check_get<double,2>();
    check_get<double,3>();
    check_get<double,4>();
    check_get<double,5>();
    check_set<float,1>();
    check_set<float,2>();
    check_set<float,3>();
    check_set<float,4>();
    check_set<float,5>();
    check_set<double,1>();
    check_set<double,2>();
    check_set<double,3>();
    check_set<double,4>();
    check_set<double,5>();
    return boost::report_errors();
    }
