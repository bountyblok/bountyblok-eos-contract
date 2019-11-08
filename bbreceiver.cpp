#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;

class [[eosio::contract("bbreceiver")]] bbreceiver : public contract {
  public:
  	 using contract::contract;
	 
	[[eosio::on_notify("bountyblok::notichlgdone")]]
	void onnotified(name receiver, name account_name, std::string challenge_name, std::string challenge_guid, uint64_t create_date, asset reward) {
		// handle received notification for completing a challenge:
		// - transfer reward to account_name
		// - store in a multi_index table
		// - etc.
	}

	[[eosio::action]]
	void empty() {}
};

