#if !defined(BOOST_VMD_DETAIL_NUMBER_HPP)
#define BOOST_VMD_DETAIL_NUMBER_HPP

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/logical/bitor.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/replace.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/is_begin_tuple.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/tuple.hpp>
#include <boost/vmd/types.hpp>
#include <boost/vmd/detail/empty_result.hpp>
#include <boost/vmd/detail/idprefix.hpp>
#include <boost/vmd/detail/is_number_concatenate.hpp>
#include <boost/vmd/detail/mods.hpp>

#define BOOST_VMD_DETAIL_NUMBER_REGISTRATION_PREFIX BOOST_VMD_SUBSET_REGISTER_

#define BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(parameter) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_NUMBER_REGISTRATION_PREFIX, \
		parameter \
		) \
/**/

#define BOOST_VMD_DETAIL_IS_NUMBER_CONC_ICTUPLE(vpar) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_TUPLE(vpar), \
		BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_TUPLE, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(vpar) \
/**/

#define BOOST_VMD_DETAIL_IS_NUMBER_CONC_CTUPLE(vpar) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_IS_NUMBER_CONC_ICTUPLE(vpar)) \
/**/

#define BOOST_VMD_DETAIL_IS_NUMBER_CONC(parameter) \
	BOOST_VMD_DETAIL_IS_NUMBER_CONC_CTUPLE \
		( \
		BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(parameter) \
		) \
/**/

#define BOOST_VMD_DETAIL_IS_NUMBER_IRESULT(parameter) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_BITOR \
			( \
			BOOST_PP_IS_EMPTY(parameter), \
			BOOST_VMD_IS_BEGIN_TUPLE(parameter) \
			), \
		BOOST_VMD_IDENTITY(0), \
		BOOST_VMD_DETAIL_IS_NUMBER_CONC \
		) \
	(parameter) \
/**/

#define BOOST_VMD_DETAIL_IS_NUMBER(parameter) \
	BOOST_VMD_IDENTITY_RESULT(BOOST_VMD_DETAIL_IS_NUMBER_IRESULT(parameter)) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_GET_TP(tuple) \
	BOOST_PP_TUPLE_REPLACE \
		( \
		tuple, \
		0, \
		BOOST_PP_TUPLE_ELEM \
			( \
			1, \
			BOOST_PP_TUPLE_ELEM(0,tuple) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_GET(tvseq) \
	BOOST_VMD_DETAIL_NUMBER_GET_TP(BOOST_VMD_BEGIN_TUPLE(tvseq,BOOST_VMD_RETURN_AFTER)) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_TUPLE_TYPE(tuple) \
	BOOST_PP_EQUAL \
		( \
		BOOST_PP_TUPLE_ELEM(0,tuple), \
		BOOST_VMD_TYPE_NUMBER \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_ITUPLE(tuple) \
	BOOST_PP_IIF \
		( \
		BOOST_PP_EQUAL \
			( \
			BOOST_PP_TUPLE_SIZE(tuple), \
			2 \
			), \
		BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_TUPLE_TYPE, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(tuple) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_TUPLE(tuple) \
	BOOST_VMD_IDENTITY_RESULT \
		( \
		BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_ITUPLE(tuple) \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST(tvseq) \
	BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST_TUPLE \
		( \
		BOOST_VMD_BEGIN_TUPLE(tvseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_IVSEQ(tvseq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_IS_BEGIN_TUPLE(tvseq), \
		BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_TEST, \
		BOOST_VMD_IDENTITY(0) \
		) \
	(tvseq) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_NEXT_PEN(tvseq) \
	BOOST_VMD_IDENTITY_RESULT \
		( \
		BOOST_VMD_DETAIL_NUMBER_NEXT_PEN_IVSEQ(tvseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_PROCESS_VSEQ(tvseq) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_NUMBER_NEXT_PEN(tvseq), \
		BOOST_VMD_DETAIL_NUMBER_GET, \
		BOOST_VMD_DETAIL_EMPTY_RESULT \
		) \
	(tvseq) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_PROCESS(vseq) \
	BOOST_VMD_DETAIL_NUMBER_PROCESS_VSEQ \
		( \
		BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(vseq) \
		) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_SPLIT(vseq) \
    BOOST_PP_IIF \
      ( \
      BOOST_PP_BITOR \
      	( \
      	BOOST_VMD_IS_EMPTY(vseq), \
      	BOOST_VMD_IS_BEGIN_TUPLE(vseq) \
      	), \
      BOOST_VMD_DETAIL_EMPTY_RESULT, \
      BOOST_VMD_DETAIL_NUMBER_PROCESS \
      ) \
    (vseq) \
/**/

#define BOOST_VMD_DETAIL_NUMBER_BEGIN(vseq) \
	BOOST_PP_TUPLE_ELEM(0,BOOST_VMD_DETAIL_NUMBER_SPLIT(vseq)) \
/**/

#define BOOST_VMD_DETAIL_NUMBER(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_MODS_IS_RESULT_AFTER \
			( \
			BOOST_VMD_DETAIL_NEW_MODS(BOOST_VMD_ALLOW_AFTER,__VA_ARGS__) \
			), \
		BOOST_VMD_DETAIL_NUMBER_SPLIT, \
		BOOST_VMD_DETAIL_NUMBER_BEGIN \
		) \
	(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)) \
/**/

#define BOOST_VMD_DETAIL_INTERNAL_NUMBER(vseq) \
	BOOST_VMD_DETAIL_NUMBER(vseq,BOOST_VMD_RETURN_AFTER) \
/**/

#endif /* BOOST_VMD_DETAIL_NUMBER_HPP */
