//
// Created by sebastien-manicon on 14/11/2025.
//

#include <random>

#define APPROVALS_GOOGLETEST
#include "ApprovalTests.hpp"
#include "GildedRose.h"
#include "gtest/gtest.h"

bool operator==(const Item &li, const Item &ri) {
    return li.name == ri.name
           && li.sellIn == ri.sellIn
           && li.quality == ri.quality;
}

std::ostream &operator<<(std::ostream &os, const Item &item) {
    return os << "Item (" << item.name << ", " << item.sellIn << ", " << item.quality << ")";
}
/*
TEST(gildedRose, should_decrement_sellin_when_foo_item_updated) {
    std::vector<Item> items{Item("foo", 0, 0)};
    GildedRose rose(items);
    rose.updateQuality();

    ASSERT_EQ(items[0], Item("foo", -1, 0));
}

TEST(gildedRose, should_decrement_quality_and_sellin_when_foo_item_updated_with_a_quality_of_1) {
    std::vector<Item> items{Item("foo", 0, 1)};
    GildedRose rose(items);
    rose.updateQuality();

    ASSERT_EQ(items[0], Item("foo", -1, 0));
}

TEST(gildedRose, should_do_nothing_when_sulfura_item_is_updated) {
    std::vector<Item> items{Item("Sulfuras, Hand of Ragnaros", 0, 1)};
    GildedRose rose(items);
    rose.updateQuality();

    ASSERT_EQ(items[0], Item("Sulfuras, Hand of Ragnaros", 0, 1));
}

TEST(gildedRose, should_add_2_of_quality_and_decrement_sellin_when_aged_brie_is_updated) {
    std::vector<Item> items{Item("Aged Brie", 0, 0)};
    GildedRose rose(items);
    rose.updateQuality();

    ASSERT_EQ(items[0], Item("Aged Brie", -1, 2));
}

TEST(gildedRose, should_decrement_sellin_when_backstaged_updated) {
    std::vector<std::unique_ptr<Item>> items{Item("Backstage passes to a TAFKAL80ETC concert", 0, 0)};
    GildedRose rose(items);
    rose.updateQuality();

    ASSERT_EQ(items[0], Item("Backstage passes to a TAFKAL80ETC concert", -1, 0));
}

*/
// std::mt19937 rng(42);
// std::uniform_int_distribution<std::mt19937::result_type> item_count(0, 100);
// std::uniform_int_distribution<std::mt19937::result_type> namernd(0, names.size() - 1);
// std::uniform_int_distribution<std::mt19937::result_type> sellin(-10, 70);
// std::uniform_int_distribution<std::mt19937::result_type> quality(-10, 70);


TEST(Golden, Master) {
    std::mt19937 rng(42);

    std::vector<std::string> names {
        "Aged Brie",
        "Backstage passes to a TAFKAL80ETC concert",
        "Sulfuras, Hand of Ragnaros",
        "unknow"
    };

    std::uniform_int_distribution<std::mt19937::result_type> item_count(0, 100);
    std::uniform_int_distribution<std::mt19937::result_type> name_index(0, names.size() - 1);
    std::uniform_int_distribution<std::mt19937::result_type> sellin(-10, 70);
    std::uniform_int_distribution<std::mt19937::result_type> quality(-10, 70);


    std::ostringstream os;
    for (int j=0; j < 1000; j++) {
        std::vector<std::unique_ptr<Item>> items;
        for (int i = 0; i < 100; ++i) {
            std::unique_ptr<Item> item = ItemFactory::create_item(
                names[name_index(rng)],
                sellin(rng),
                quality(rng)
            );
            items.push_back(std::move(item));
        }

        GildedRose rose(items);
        rose.updateQuality();

        for (const auto &item : rose.items) {
            os << *item << ",";
        }
        os << std::endl;
    }

    ApprovalTests::Approvals::verify(os.str());
}