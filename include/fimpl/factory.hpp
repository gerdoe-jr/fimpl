#pragma once

#include "compile_time_str.hpp"

/*
    * As you can see there, you can't use it in case of variable
    * constructor arguments as it will lead to different template
    * instantiation and different function signature
*/

template<compile_time_str Name, typename Interface, typename ...Tn>
extern Interface *create_instance(Tn ...args);
