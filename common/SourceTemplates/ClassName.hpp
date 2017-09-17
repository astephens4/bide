/*!
 *  \file ClassName.hpp
 *
 *  \brief What is declared/defined in this file
 */
#if !defined(PROJ_CLASS_NAME_HPP)
#define PROJ_CLASS_NAME_HPP 1

// Standard library includes
#include <cstdint>
#include <cstddef>

// Project includes
// (none)

// Forward Declarations

namespace Namespace {

/*!
 * \class ClassName
 * \brief Brief description of the class
 *
 * \par Full Description
 * Full Description of the class
 */
class ClassName {
public:

    //******************************************************************************************************************
    // Public Definitions
    //******************************************************************************************************************

    /// Description of the enum
    enum Enum : std::uint8_t {
        VALUE_1,    ///< Any necessary description of VALUE_1
        VALUE_2     ///< Any necessary description of VALUE_2
    };

    /// Description of the public const, if necessary
    static std::uint32_t const PUBLIC_CONST = 42U;

    //******************************************************************************************************************
    // Public Methods
    //******************************************************************************************************************

    /*!
     * \brief Get the number of instances of this class
     *
     * Get the total number of active instances of this class. This gets updated on object construction and destruction.
     *
     * \return Number of active instance
     */
    static unsigned int InstCount(void);

    /*!
     * \brief Constructor
     *
     * Create an instance of this class based on an int and float.
     *
     * \param  [in]    param1  Description of the parameter
     * \param  [out]   param2  Description of this parameter
     */
    ClassName(int param1, float &param2);

    /*!
     * \brief Convert a double to a string
     *
     * Converts the double to an ASCII encoded string.
     *
     * \param  [in]    d       The double to convert to a string
     * \param  [out]   pStr    The double as a printable string
     *
     * \return The number of bytes in the output string
     */
    int PublicMethod1(double d, char *pStr);

protected:
    //******************************************************************************************************************
    // Protected Methods
    //******************************************************************************************************************

private:
    //******************************************************************************************************************
    // Private Methods
    //******************************************************************************************************************

    //******************************************************************************************************************
    // Member Data
    //******************************************************************************************************************

}; // end ClassName

} // end Namespace

#endif // !defined(PROJ_CLASS_NAME_HPP)

