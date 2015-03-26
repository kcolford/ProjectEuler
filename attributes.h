/* attributes.h -- support adding attributes in an easy way */
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#if defined __GNUC__ && __GNUC__ > 2
# define GNU_ATTRIBUTE(alist) __attribute__((alist))
#else
# define GNU_ATTRIBUTE(alist)
#endif

#ifdef __cplusplus
# define CXX_ONLY(stuff) stuff
#else
# define CXX_ONLY(stuff)
#endif

#define ATTRIBUTE_PURE                          \
  GNU_ATTRIBUTE(__pure__)

#define ATTRIBUTE_CONST                         \
  GNU_ATTRIBUTE(__const__)

#define ATTRIBUTE_LEAF                          \
  GNU_ATTRIBUTE(__leaf__)

#define ATTRIBUTE_MALLOC                        \
  GNU_ATTRIBUTE(__malloc__)

#define ATTRIBUTE_NONNULL(argidx)               \
  GNU_ATTRIBUTE(__nonnull__(argidx))

#define ATTRIBUTE_NONNULL_LIST(alist)           \
  GNU_ATTRIBUTE(__nonnull__ alist)

#define ATTRIBUTE_NOTHROW                       \
  GNU_ATTRIBUTE(__nothrow__)                    \
  CXX_ONLY(throw ())

#define ATTRUBUTE_FLATTEN                       \
  GNU_ATTRIBUTE(__flatten__)

#define ATTRIBUTE_FORMAT(type, stridx, fst_argidx)      \
  GNU_ATTRIBUTE(__format__(type, stridx, fst_argidx))

#define ATTRIBUTE_NO_SANTIZE                    \
  GNU_ATTRIBUTE(__no_sanitize_address__)

#define ATTRIBUTE_USE_RETURN                    \
  GNU_ATTRIBUTE(__warn_unused_result__)

#endif
