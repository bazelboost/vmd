#if !defined(BOOST_VMD_DETAIL_AFTER_NUMBER_RE_COMMON_HPP)
#define BOOST_VMD_DETAIL_AFTER_NUMBER_RE_COMMON_HPP

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/variadic/elem.hpp>

#define BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_CAT(...) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_AFTER_NUMBER_, \
		BOOST_PP_DEC(BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__)) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_CAT(...) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_, \
		BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_PEN_CAT(...) \
	BOOST_PP_CAT \
		( \
		BOOST_VMD_DETAIL_AFTER_NUMBER_NEXT_PEN_, \
		BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_AFTER_NUMBER_RE_COMMON_HPP */
