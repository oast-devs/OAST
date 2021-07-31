# Set of coding convention to be followed to achieve a compliant software

# Types_1 Sized ints

Avoid using standard types (int, char, long). Use stdint.h types instead (int8_t, uint64_t, ...). An exception is using char * to define strings.

# Casting_1 Casting pointers shall be avoided

Casting a pointer of undefined length to a struct pointer for example is forbidden. Exceptions are allowed for malloc() and NULL

# Casting_2 Casting unsigned to signed type of the same size shall be avoided

As an example, casting uint8_t to int8_t is forbidden due to the undefined behaviour of converting >127 uint8_t to int8_t and vice-versa.
An exception is the use of an explicit check before the casting.

# Casting_3 Casting a type to a smaller type shall be avoided
As an example, casting int32_t to int16_t is forbidden due to the undefined behaviour of converting >32768 int32 to int16
An exception is the extraction of byte fields from a larger data type

