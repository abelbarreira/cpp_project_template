#include <iostream>

#include "nlohmann/json.hpp"


#include "bar.h"

/**
 * @brief fn_branch
 *
 * @param do_branch1
 * @param do_branch2
 * @return int
 */
int fn_branch(bool do_branch1, bool do_branch2)
{
    if (do_branch1 || do_branch2)
        return 0;

    return 1;
}
