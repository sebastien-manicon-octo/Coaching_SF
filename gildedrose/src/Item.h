//
// Created by sebastien-manicon on 18/11/2025.
//

#ifndef GILDED_ROSE_REFACTORING_KATA_CPP_ITEM_H
#define GILDED_ROSE_REFACTORING_KATA_CPP_ITEM_H
#include <functional>
#include <map>
#include <memory>
#include <string>



class Item {
public:
    std::string name;
    int sellIn;
    int quality;

    Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) {
    }

    virtual void update_quality() = 0;

    void decrement_quality();

    void increment_quality();

    void decrement_sellin();

    void reset_quality();
};

class AgedBrie : public Item {
public:
    explicit AgedBrie(const Item & item);
    explicit AgedBrie(int sellin, int quality);

    void update_quality() override;
};

class Backstage : public Item {
public:
    explicit Backstage(const Item & item);
    explicit Backstage(int sellin, int quality);

    void update_quality() override;
};

class Sulfuras : public Item {
public:
    explicit Sulfuras(const Item & item);
    explicit Sulfuras(int sellin, int quality);

    void update_quality() override;
};

class OtherItem : public Item {
public:
    explicit OtherItem(const Item & item);
    explicit OtherItem(const std::string &name, int sellin, int quality);

    void update_quality() override;
};

static const std::map<std::string, std::function<std::unique_ptr<Item>(int, int)>> mapFactory = {
    {"Aged Brie", [](int sellin, int quality) {return std::make_unique<AgedBrie>(sellin, quality);}},
    {"Backstage passes to a TAFKAL80ETC concert", [](int sellin, int quality) {return std::make_unique<Backstage>(sellin, quality);}},
    {"Sulfuras, Hand of Ragnaros", [](int sellin, int quality) {return std::make_unique<Sulfuras>(sellin, quality);}}
};
class ItemFactory {
public:
    static std::unique_ptr<Item> create_item(const std::string & name, int sellin, int quality) {
        auto it = mapFactory.find(name);
        if (it != mapFactory.end()) {
            return it->second(sellin, quality);
        }

        return std::make_unique<OtherItem>(name, sellin, quality);
    }
private:
    ItemFactory(){}
};
#endif //GILDED_ROSE_REFACTORING_KATA_CPP_ITEM_H
