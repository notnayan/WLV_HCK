package com.question3;

import akka.actor.AbstractActor;

public class BankAccount extends AbstractActor {
	private volatile int amount = 100;

	public BankAccount() {
		System.out.println("The Initial balance is " + amount + ".");
	}

	@Override
	public Receive createReceive() {
		return receiveBuilder()
			.match(Deposit.class, this::onDeposit) // Match Deposit messages and call onDeposit method
			.match(Withdraw.class, this::onWithdraw) // Match Withdraw messages and call onWithdraw method
			.build();
	}

	private void onDeposit(Deposit deposit) {
		synchronized (this) {
			amount += deposit.amount; // Increase the amount by the deposited amount
			System.out.println(
				deposit.amount + " has been successfully deposited to your account. Your new balance is " + amount + ".");
		}
	}

	private void onWithdraw(Withdraw withdraw) {
		synchronized (this) {
			amount += withdraw.amount; // Increase the amount by the withdrawn amount
			System.out.println(
				Math.abs(withdraw.amount) + " has been successfully withdrawn from your account. Your new balance is "
					+ amount + ".");
		}
	}
}
