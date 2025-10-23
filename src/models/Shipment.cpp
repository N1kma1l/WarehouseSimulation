#include "models/Shipment.h"

ShipmentItem::ShipmentItem(int id, const std::string& name, int packs, double quantity, double cost) :
    product_id(id),
    product_name(name),
    packs_count(packs),
    total_quantity(quantity),
    total_cost(cost) {}

Shipment::Shipment(int id, int store_id, int day) :
    shipment_id_(id),
    store_id_(store_id),
    shipment_day_(day),
    total_packs_(0),
    total_cost_(0.0),
    is_completed_(false) {}

void Shipment::addItem(int product_id, const std::string& product_name, int packs, double quantity, double cost) {
    if (packs > 0 && cost >= 0) {
        items_.emplace_back(product_id, product_name, packs, quantity, cost);
        total_packs_ += packs;
        total_cost_ += cost;
    }
}