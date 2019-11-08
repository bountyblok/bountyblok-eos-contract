# bountyblok-eos-contract

Bountyblok smart contract is powered by the bountyblok.io engine and will execute on chain the results of a completed challenge. 

This will notify the external contract that implements the on_notify with the results of the challenge.

bbreceiver.cpp is an example of an external contract on how to define and implement the on_notify.
