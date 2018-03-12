//
//  equiv_address_info.cpp
//  blocksci
//
//  Created by Harry Kalodner on 3/7/18.
//

#include "equiv_address_info.hpp"

namespace blocksci {
    constexpr char DedupAddressInfo<DedupAddressType::PUBKEY>::name[];
    constexpr char DedupAddressInfo<DedupAddressType::SCRIPTHASH>::name[];
    constexpr char DedupAddressInfo<DedupAddressType::MULTISIG>::name[];
    constexpr char DedupAddressInfo<DedupAddressType::NULL_DATA>::name[];
    constexpr char DedupAddressInfo<DedupAddressType::NONSTANDARD>::name[];
    
    template<DedupAddressType::Enum type>
    struct EquivAddressNameFunctor {
        static std::string f() {
            return DedupAddressInfo<type>::name;
        }
    };
    
    std::string equivAddressName(DedupAddressType::Enum type) {
        static auto table = make_static_table<DedupAddressType, EquivAddressNameFunctor>();
        auto index = static_cast<size_t>(type);
        if (index >= DedupAddressType::size)
        {
            throw std::invalid_argument("combination of enum values is not valid");
        }
        return table[index];
    }
}
