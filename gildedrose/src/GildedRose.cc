#include "GildedRose.h"

using namespace std;

GildedRose::GildedRose(const std::vector<std::unique_ptr<Item>> &items) {
    for (int i = 0; i < items.size(); i++) {
        auto &item = *items[i];
        this->items.push_back(
            ItemFactory::create_item(item.name, item.sellIn, item.quality)
            );
    }
}

void GildedRose::updateQuality() {
    for (int i = 0; i < items.size(); i++) {
        auto &item = items[i];
        item->update_quality();
    }
}
