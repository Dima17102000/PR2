package a11848552;

/**
 * Tradeable objects can be traded and stored in inventories 
 */
public interface Tradeable {
    /**
     * Returns price of the object
     * @return price of the object
     */
	int getPrice();

    /**
     * Returns weight of the object
     * @return weight of the object
     */
	int getWeight();

    /**
     * Caution: this method transfers the item from from's inventory to to's inventory
     * without any checks. It has to be ensured that all necessary conditions for the
     * transfer are met before calling this function-
     * The default implementation calls removeFromInventory on from and addToInventory
     * on to and returns true if both calls succeeded (returned true)
     * @param from object is taken from from's inventory
     * @param to object is transferre to to's inventory
     * @return true, if transfer succeeds, false otherwise
     */
	private boolean transfer(Trader from, Trader to) {
		
		if (from == null || to == null || from == to) {
            throw new IllegalArgumentException("Invalid traders.");
        }
        if (!from.possesses(this)) {
            return false;
        }
        if (!to.hasCapacity(this.getWeight())) {
            return false;
        }
        from.removeFromInventory(this);
        to.addToInventory(this);
        return true;
	}

    /**
     * If giver or taker is null or they are the same object,
     * an IllegalArgumentException must be thrown;
     * <p>
     * giver gives the object away for free. Default implementation checks if the giver
     * has the object (possesses method) and the taker has enough capacity in the
     * inventory (hasCapacity). If any of these checks fail, the method returns false.
     * <p>
     * Otherwise the item is transferred from the giver's inventory to the taker's
     * inventory (transfer method) and the return value of the transfer call is returned
     * @param giver the one who gives the object away
     * @param taker the one who receives the object
     * @return true, if transfer was successful, false otherwise
     */
	default boolean give(Trader giver, Trader taker) {
		if (giver == null || taker == null || giver == taker) {
            throw new IllegalArgumentException("Invalid traders.");
        }
        if (!giver.possesses(this)) {
            return false;
        }
        if (!taker.hasCapacity(this.getWeight())) {
            return false;
        }
        boolean success = giver.removeFromInventory(this);
        if (success) {
            success = taker.addToInventory(this);
            if (!success) {
                // Return the item to the giver if adding to inventory fails
                giver.addToInventory(this);
            }
        }
        return success;
    }

    /**
     * If seller or buyer is null or they are the same object, an IllegalArgumentException
     * must be thrown;
     * <p>
     * default implementation checks if the seller has the object (possesses method), the
     * buyer can afford the object (canAfford method) and the buyer has enough capacity
     * in the inventory (hasCapacity). If any of these checks fail, the method returns
     * false.
     * <p>
     * Otherwise the buyer pays the price (pay method), the seller receives the price paid
     * (earn method), The item is transferred from the seller's inventory to the buyer's
     * inventory (transfer method) and the return value of the transfer call is returned
     * @param seller the one who sells the object
     * @param buyer the one who buys the object
     * @return true, if the purchase is successful, false otherwise
     */
	default boolean purchase(Trader seller, Trader buyer) {
		return this.give(seller, buyer);
	}

    /**
     * If target is null, an IllegalArgumentException must be thrown;
     * use the object on the target
     * @param target target of the object's usage (which will typically inflicted by the magic
     * effects)
     */
	void useOn(MagicEffectRealization target);
}