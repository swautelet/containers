#ifndef IS_CONST_HPP
# define IS_CONST_HPP

namespace ft
{
    template <bool isConst, typename isFalse, typename isTrue>
    struct chooseConst {};

    template <typename isFalse, typename isTrue>
    struct chooseConst<false, isFalse, isTrue>
    {
        typedef isFalse type;
    };

    template <typename isFalse, typename isTrue>
    struct chooseConst<true, isFalse, isTrue>
    {
        typedef isTrue type;
    };
};


#endif