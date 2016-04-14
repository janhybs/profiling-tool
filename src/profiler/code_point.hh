#ifndef CODE_POINT_HH
#define CODE_POINT_HH

#include <iostream>

using namespace std;

namespace profiler {


/**
 * Macro to generate constexpr CodePoint object.
 */
#define CODE_POINT(tag) profiler::CodePoint(tag, __FILE__, __func__, __LINE__)

/**
 * Macro to generate constexpr CodePoint object.
 */
#define CODE_POINT_EXT(tag, subtag) profiler::CodePoint(tag, subtag, __FILE__, __func__, __LINE__)

    
/**
 * Variable which represents value when no subtag was specified in CodePoint class
 */
#define PROFILER_EMPTY_SUBTAG ""

/**
 * Variable used for default value in hash process
 */
#define PROFILER_HASH_DEFAULT 0


/**
 * @brief Class that represents point in the code.
 *
 * This class allow construction at compile time. And includes the information about the code point as well
 * as the 'tag' of the timer and compile-time computed hashes of this 'tag'. The @p hash_ is long one with
 * very small probability of collisions - this we use for comparison of tags. The @p hash_idx_ is the long hash modulo
 * length of the array of Timer's children, this is used for fast loop up into this array that servers as a simple hash table.
 */
class CodePoint {
public:
    constexpr CodePoint(const char *tag, const char * file, const char * func, const unsigned int line)
    : tag_(tag), subtag_(PROFILER_EMPTY_SUBTAG), file_(file), func_(func), line_(line),
      hash_(str_hash(tag, PROFILER_HASH_DEFAULT))
    {};
    constexpr CodePoint(const char *tag, const char *subtag, const char * file, const char * func, const unsigned int line)
    : tag_(tag), subtag_(subtag), file_(file), func_(func), line_(line),
      hash_(str_hash(subtag, str_hash(tag, PROFILER_HASH_DEFAULT)))
    {};
    
protected:
    /// Tag of the code point.
    const char * const tag_;

    /// Subtag of the code point.
    const char * const subtag_;

    /// file name of the code point
    const char * const file_;

    /// file name of the code point
    const char * const func_;

    /// file name of the code point
    const unsigned int line_;

    /// Full 32-bit hash of the tag ( practically no chance of collision)
    unsigned int hash_;
    
    /**
     * @brief Function for compile-time hash computation.  (Needs C++x11 standard.)
     * Input, @p str, is constant null terminated string, result is unsigned int (usually 4 bytes).
     * Function has to be recursive, since standard requires that the body consists only from the return statement.
     *
     * SALT is hash for the empty string. Currently zero for simpler testing.
     */
    static inline constexpr unsigned int str_hash(const char * str, unsigned int default_value) {
        #define SALT 0 //0xef50e38f
        return (*str == 0 ? SALT : default_value + str_hash(str + 1, PROFILER_HASH_DEFAULT) * 101 + (unsigned int)(*str));
    }
    
    
    /**
     * define stream << operator
     */
    friend std::ostream & operator <<(std::ostream&, const CodePoint&);
};

} // namespace profiler
#endif  // CODE_POINT_HH