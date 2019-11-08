#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;

class [[eosio::contract("bountyblok")]] bountyblok : public contract {
  public:
  	 using contract::contract;

	 /**
	  *  Executed when a bountyblok challenge has completed.
	  *  Will try to notify the receiver contract associated to this challenge
	  *  with a carbon copy of the challenge result parameters.
	  *  At the minimum you have the account_name that completed the challenge,
	  *  the challenge name, and the reward (example: "25.0000 KARMA")
	  */
	[[eosio::action]]
	void execchlgdone(name receiver, name account_name, std::string challenge_name, std::string challenge_guid, uint64_t create_date, asset reward) {
		notify_challenge_done_action notichlgdone(get_self(), {get_self(), "active"_n});
		notichlgdone.send(receiver, account_name, challenge_name, challenge_guid, create_date, reward);
	}

	[[eosio::action]]
	void notichlgdone(name receiver, name account_name, std::string challenge_name, std::string challenge_guid, uint64_t create_date, asset reward) {
		require_auth(get_self());
		require_recipient(receiver);
	}

	/**
	 *  Empty actions executed on chain
	 */
	[[eosio::action]]
	void logtask(std::string task_guid, std::string task_data, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addbadge(std::string badge_guid, std::string badge_name, std::string badge_hash, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addtitle(std::string title_guid, std::string title_name, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addtask(std::string task_guid, std::string task_data, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addchallenge(std::string challenge_guid, std::string challenge_data, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void achievement(std::string ach_guid, std::string ach_name, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addsocial(std::string from, std::string to, std::string social_data, std::string create_date) {}

	
	/**
	 * Action wrappers
	 */
	using notify_challenge_done_action = action_wrapper<"notichlgdone"_n, &bountyblok::notichlgdone>;
};

