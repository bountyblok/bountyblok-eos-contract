#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;

class [[eosio::contract("bbreceiver")]] bbreceiver : public contract {
  public:
  	 using contract::contract;
	 
	/**
	 *  Implementing the bountyblok::notichlgdone allows this smart contract
	 *  to obtain a copy of the parameters when a challenge has been completed.
	 *  Ex: Transfer the reward to the account_name who completed the Challenge.
	 *  Ex: Simply store it in a Datatable to process later.
	 */
	[[eosio::on_notify("bountyblok::notichlgdone")]]
	void onnotified(name receiver, name account_name, std::string challenge_name, std::string challenge_guid, uint64_t create_date, asset reward) {
		// handle received notification for completing a challenge
	}

	[[eosio::action]]
	void empty() {}
};

