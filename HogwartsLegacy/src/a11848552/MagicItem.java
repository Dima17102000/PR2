package a11848552;

/**
 * MagicItems are items that can cause magic effects on other objects. So they are a source
 * of magic. As items they can be traded and they also can be the target of magic effects  
 */
public abstract class MagicItem implements Tradeable, MagicEffectRealization, MagicSource {
	/**
	 * Must not be null or empty
	 * */
	private String name;
	/**
	 * Number of usages remaining; must not be negative
	 */
	private int usages;
	/**
	 * Must not be negative
	 */
	private int price;
	/**
	 * must not be negative
	 */
	private int weight;
	

	/**
	 * @param name name
	 * @param usages number of usages still left
	 * @param price price
	 * @param weight weight
	 */
	public MagicItem(String name, int usages, int price, int weight){
		this.name = name;
        this.price = price;
        this.usages = usages;
        this.weight = weight;
	}

    /**
     * Returns value of usages (for access from deriving classes)
     * @return value of instance variable usages
     */
	public int getUsages() {
		return usages;
	}

    /**
     * If usages > 0 reduce usage by 1 and return true, otherwise return false
     * @return returns true if usage is still possible
     */
	public boolean tryUsage() {
		if (usages > 0) {
            usages--;
            return true;
        } else {
            return false;
        }
	}

    /**
     * Returns "use" if usages is equal to 1, "uses" otherwise
     * @return "use" or "uses" depending on the value of usages
     */
	public String usageString() {
		 if (usages == 0) {
	            return "No usages remaining.";
	        } else if (usages == 1) {
	            return "1 usage remaining.";
	        } else {
	            return usages + " usages remaining.";
	        }
	}

    /**
     * returns empty string. Is overridden in deriving classes as needed
     * @return ""
     */
	public String additionalOutputString() {
		return "This magic item has additional effects.";

	}

	public String toString() {
		return "Magic Item: " + name + "\n" +
	               "Usages: " + usages + "\n" +
	               "Price: " + price + "\n" +
	               "Weight: " + weight + "\n" +
	               "Usage String: " + usageString() + "\n" +
	               "Additional Output: " + additionalOutputString();
	}

	public String getName()
	{
		return name;
	}
	public int getPrice() {
		return price;
	}
    
	public int getWeight() {
		return weight;
	}
	  
	public boolean provideMana(MagicLevel levelNeeded, int amount) {
		return true;
 }

	public void takeDamagePercent(int percentage) {
		usages *= (1-percentage/100);
	}
}