//
// Created by sebastien-manicon on 18/11/2025.
//

#include "Item.h"

#include <iostream>


void Item::update_quality() {
}

void Item::decrement_quality() {
    quality -= 1;
}

void Item::increment_quality() {
    quality += 1;
}

void Item::decrement_sellin() {
    sellIn -= 1;
}

void Item::reset_quality() {
    quality = 0;
}

AgedBrie::AgedBrie(const Item &item) : Item(item) {
}

AgedBrie::AgedBrie(int sellin, int quality) : Item("Aged Brie", sellin, quality) {
}

void AgedBrie::update_quality() {
    decrement_sellin();
    if (quality < 50) increment_quality();
    if (sellIn < 0 && quality < 50) increment_quality();
}

Backstage::Backstage(const Item &item) : Item(item) {
}

Backstage::Backstage(int sellin, int quality) : Item("Backstage passes to a TAFKAL80ETC concert", sellin, quality) {
}


void Backstage::update_quality() {
    if (quality < 50) increment_quality();
    if (sellIn < 11 && quality < 50) increment_quality();
    if (sellIn < 6 && quality < 50) increment_quality();

    decrement_sellin();

    if (sellIn < 0) reset_quality();
}

Sulfuras::Sulfuras(const Item &item) : Item(item) {
}

Sulfuras::Sulfuras(int sellin, int quality) : Item("Sulfuras, Hand of Ragnaros", sellin, quality) {
}

void Sulfuras::update_quality() {
}

OtherItem::OtherItem(const Item &item) : Item(item) {
}

OtherItem::OtherItem(const std::string &name, int sellin, int quality) : Item(name, sellin, quality) {
}

void OtherItem::update_quality() {
    decrement_sellin();
    if (quality > 0) decrement_quality();
    if (sellIn < 0 && quality > 0) decrement_quality();
}
