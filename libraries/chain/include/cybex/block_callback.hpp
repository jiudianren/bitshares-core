#pragma once
#include <graphene/chain/protocol/base.hpp>
#include <graphene/chain/database.hpp>
namespace graphene {
namespace chain {


class block_callback
{
    bool snapshot_done;
public:
    block_callback() {}
    void handler(database & db);
    void snapshot(database & db);

    static uint64_t snapshot_at_block_num;
    static uint8_t  snapshot_in_day;
    static uint8_t snapshot_in_hour;
    static uint8_t snapshot_in_minute;

private:
   void process_crowdfund(database & db) const ;
   void auto_withdraw(database & db,const crowdfund_object & crowdfund) const;
   void crowdfund_ended(database & db,const crowdfund_object & crowdfund) const;
};




} }
