package a11848552;

	public enum MagicLevel {
		NOOB(50, "*"),
	    ADEPT(100, "**"),
	    STUDENT(200, "***"),
	    EXPERT(500, "****"),
	    MASTER(1000, "*****");

	    private int mana;
	    private String representation;

	    MagicLevel(int mana, String representation) {
	        this.mana = mana;
	        this.representation = representation;
	    }

	    public int toMana() {
	        return mana;
	    }

	    @Override
	    public String toString() {
	        return representation;
	    }
}