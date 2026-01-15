#pragma once

#include <memory>
#include <vector>

#include "Item.h"

class GildedRose
{
public:
    std::vector<std::unique_ptr<Item>> items;
    explicit GildedRose(const std::vector<std::unique_ptr<Item>> & items);

    void updateQuality();
};
