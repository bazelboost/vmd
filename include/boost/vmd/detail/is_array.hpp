#if !defined(BOOST_VMD_DETAIL_IS_ARRAY_HPP)
#define BOOST_VMD_DETAIL_IS_ARRAY_HPP

#include <boost/preprocessor/control/iif.hpp>
#include <boost/vmd/identity.hpp>
#include <boost/vmd/tuple/is_tuple.hpp>
#include <boost/vmd/detail/is_array_common.hpp>

#define BOOST_VMD_DETAIL_IS_ARRAY(vseq) \
	BOOST_VMD_IDENTITY_RESULT \
		( \
		BOOST_PP_IIF \
			( \
			BOOST_VMD_IS_TUPLE(vseq), \
			BOOST_VMD_DETAIL_IS_ARRAY_SYNTAX, \
			BOOST_VMD_IDENTITY(0) \
			) \
		(vseq) \
		) \
/**/

#endif /* BOOST_VMD_DETAIL_IS_ARRAY_HPP */
