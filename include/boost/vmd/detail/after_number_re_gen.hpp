#if !defined(BOOST_VMD_DETAIL_AFTER_NUMBER_RE_GEN_HPP)
#define BOOST_VMD_DETAIL_AFTER_NUMBER_RE_GEN_HPP

#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/logical/not.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/variadic/elem.hpp>
#include <boost/vmd/gen_one.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/detail/after_number_common.hpp>
#include <boost/vmd/detail/after_number_re_common.hpp>
#include <boost/vmd/detail/is_number.hpp>
#include <boost/vmd/detail/paren_or_empty.hpp>

#define BOOST_VMD_DETAIL_AFTER_NUMBER_MAXIMUM 5 \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_4(...) \
	BOOST_PP_NOT \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_PP_TUPLE_ELEM \
				( \
				0, \
				BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_CAT(__VA_ARGS__) \
					( \
					BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)), \
					BOOST_PP_DEC(BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__)) \
					) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_3(...) \
	BOOST_PP_NOT \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_PP_TUPLE_ELEM \
				( \
				0, \
				BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_CAT(__VA_ARGS__) \
					( \
					BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)), \
					BOOST_PP_DEC(BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__)) \
					) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_2(...) \
	BOOST_PP_NOT \
		( \
		BOOST_VMD_IS_EMPTY \
			( \
			BOOST_PP_TUPLE_ELEM \
				( \
				0, \
				BOOST_VMD_DETAIL_AFTER_NUMBER_PROCESS_CAT(__VA_ARGS__) \
					( \
					BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)), \
					BOOST_PP_DEC(BOOST_PP_VARIADIC_ELEM(1,__VA_ARGS__)) \
					) \
				) \
			) \
		) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_NEXT_PEN_4(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY \
			( \
			BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)) \
			), \
		BOOST_VMD_GEN_ONE, \
		BOOST_VMD_DETAIL_AFTER_NUMBER_CAT(__VA_ARGS__) \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_NEXT_PEN_3(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY \
			( \
			BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)) \
			), \
		BOOST_VMD_GEN_ONE, \
		BOOST_VMD_DETAIL_AFTER_NUMBER_CAT(__VA_ARGS__) \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_NEXT_PEN_2(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_PAREN_OR_EMPTY \
			( \
			BOOST_VMD_DETAIL_IS_NUMBER_CONCATENATE(BOOST_PP_VARIADIC_ELEM(0,__VA_ARGS__)) \
			), \
		BOOST_VMD_GEN_ONE, \
		BOOST_VMD_DETAIL_AFTER_NUMBER_CAT(__VA_ARGS__) \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_4(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_NUMBER_PEN_CAT(__VA_ARGS__)(__VA_ARGS__), \
		BOOST_VMD_DETAIL_AFTER_NUMBER_GET, \
		BOOST_VMD_DETAIL_AFTER_NUMBER_NOT_FOUND \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_3(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_NUMBER_PEN_CAT(__VA_ARGS__)(__VA_ARGS__), \
		BOOST_VMD_DETAIL_AFTER_NUMBER_GET, \
		BOOST_VMD_DETAIL_AFTER_NUMBER_NOT_FOUND \
		) \
	(__VA_ARGS__) \
/**/

#define BOOST_VMD_DETAIL_AFTER_NUMBER_2(...) \
	BOOST_PP_IIF \
		( \
		BOOST_VMD_DETAIL_AFTER_NUMBER_PEN_CAT(__VA_ARGS__)(__VA_ARGS__), \
		BOOST_VMD_DETAIL_AFTER_NUMBER_GET, \
		BOOST_VMD_DETAIL_AFTER_NUMBER_NOT_FOUND \
		) \
	(__VA_ARGS__) \
/**/

#endif /* BOOST_VMD_DETAIL_AFTER_NUMBER_RE_GEN_HPP */
