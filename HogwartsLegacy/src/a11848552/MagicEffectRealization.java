package a11848552;

import java.util.Set;

public interface MagicEffectRealization {
	
	  default void takeDamage(int amount) {
		  if (amount < 0) {
	            throw new IllegalArgumentException("Negative amount not allowed.");
	        }
	  }
	  default void takeDamagePercent(int percentage) {
		  if (percentage < 0 || percentage > 100) {
	            throw new IllegalArgumentException("Percentage must be between 0 and 100 (inclusive).");
	        }
	  }
	  default void weakenMagic(int amount) {
		  if (amount < 0) {
	            throw new IllegalArgumentException("Negative amount not allowed.");
	        }
	  }
	  default void weakenMagicPercent(int percentage) {
		  if (percentage < 0 || percentage > 100) {
	            throw new IllegalArgumentException("Percentage must be between 0 and 100 (inclusive).");
	        }
	  }
	  default void heal(int amount) {
		  if (amount < 0) {
	            throw new IllegalArgumentException("Negative amount not allowed.");
	        }
	  }
	  default void healPercent(int percentage) {
		  if (percentage < 0 || percentage > 100) {
	            throw new IllegalArgumentException("Percentage must be between 0 and 100 (inclusive).");
	        }
	  }
	  default void enforceMagic(int amount) {
		  if (amount < 0) {
	            throw new IllegalArgumentException("Negative amount not allowed.");
	        }
	  }
	  default void enforceMagicPercent(int percentage) {
		  if (percentage < 0 || percentage > 100) {
	            throw new IllegalArgumentException("Percentage must be between 0 and 100 (inclusive).");
	        }
	  }
	  default boolean isProtected(Spell s) {return false;}
	  default void setProtection(Set <AttackingSpell> attacks) {
		  if(attacks == null)
		  {
			  throw new IllegalArgumentException("Attacks must not be empty");
		  }
	  }
	  default void removeProtection(Set<AttackingSpell> attacks) {
		  if(attacks == null)
		  {
			  throw new IllegalArgumentException("Attacks must not be empty");
		  }
	  }
}