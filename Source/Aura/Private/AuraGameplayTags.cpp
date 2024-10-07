// Copyright Gravity Well Games


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 * Primary Attributes
	 */
	 
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increases physical Damage")
		);

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Intelligence"),
	FString("Increases magical Damage")
	);

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Resilience"),
	FString("Affects your Defensive Attributes: Armor and Armor Penetration")
	);

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Primary.Vigor"),
	FString("Increases Health")
	);

	/*
	 * Secondary Attributes
	*/

	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Armor"),
		FString("Based off Resilience, reduces Damage taken and improves Block Chance")
		);

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorPenetration"),
		FString("Based off Resilience, ignores percentage of enemy's Armor and increases Critical Hit Chance")
		);

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"),
		FString("Based off Armor, chance to cut incoming damage by 50%")
		);

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitChance"),
		FString("Based off Armor Penetration, chance to double your damage plus score a Critical Hit Bonus")
		);

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Based off Armor Penetration, chance to double your damage plus score a Critical Hit Bonus")
		);

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.CriticalHitResistance"),
			FString("Based off Armor, reduces Critical Hit Chance of enemies attacking you")
			);

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.HealthRegeneration"),
			FString("Based off Vigor, the amount of Health regenerated every one second")
			);

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.ManaRegeneration"),
			FString("Based off Intelligence, the amount of Mana regenerated every one second")
			);

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.MaxHealth"),
			FString("Based off Vigor, the maximum amount of Health obtainable at any given time")
			);
	
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("Based off Intelligence, the maximum amount of Mana obtainable at any given time")
		);

	/*
	 * Input Tags (Mouse and Keyboard)
	 */
	
	GameplayTags.InputTag_AbilityLeft = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.AbilityLeft"),
		FString("Input Tag for the Left Mouse Button (when using a mouse and keyboard), or the Left Shoulder Trigger (when using a gamepad controller)")
		);

	GameplayTags.InputTag_AbilityRight = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.AbilityRight"),
		FString("Input Tag for the Right Mouse Button (when using a mouse and keyboard), or the Right Shoulder Trigger (when using a gamepad controller)")
		);

	GameplayTags.InputTag_Ability1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.Ability1"),
		FString("Input Tag for the '1' Key (when using a mouse and keyboard), or the 'Up' button on the left-hand-side D-Pad (when using a gamepad controller)")
		);

	GameplayTags.InputTag_Ability2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.Ability2"),
		FString("Input Tag for the '2' Key (when using a mouse and keyboard), or the 'Down' button on the left-hand-side D-Pad (when using a gamepad controller)")
		);

	GameplayTags.InputTag_Ability3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.Ability3"),
		FString("Input Tag for the '3' Key (when using a mouse and keyboard), or the 'Left' button on the left-hand-side D-Pad (when using a gamepad controller)")
		);

	GameplayTags.InputTag_Ability4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.Ability4"),
		FString("Input Tag for the '4' Key (when using a mouse and keyboard), or the 'Right' button on the left-hand-side D-Pad (when using a gamepad controller)")
		);


	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage"),
		FString("Damage")
		);


	/**
	 ** Damage Types
	 */

	GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Fire"),
		FString("Damage will Burn")
		);

	GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Lightning"),
		FString("Damage will Electrocute")
		);

	GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Arcane"),
		FString("Damage of a Magical nature")
		);

	GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Damage.Physical"),
		FString("Damage will Injure")
		);
	
	/**
	 ** Resistances
	 **/

	GameplayTags.Attributes_Resistances_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Resistances.Fire"),
	FString("Resistant to Burning")
	);

	GameplayTags.Attributes_Resistances_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistances.Lightning"),
		FString("Resistant to Electrocution")
		);

	GameplayTags.Attributes_Resistances_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistances.Arcane"),
		FString("Resistant to Magic")
		);

	GameplayTags.Attributes_Resistances_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Resistances.Physical"),
		FString("Resistant to Physical Injuries")
		);

	/**
	 ** Debuffs
	 **/

	GameplayTags.Debuff_Damned = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Debuff.Damned"),
	FString("Debuff for Arcane Damage, as the Target loses their soul to the depths of Hell")
	);

	GameplayTags.Debuff_Burn = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Burn"),
		FString("Debuff for Fire Damage, as the flames continue to incinerate the Target")
		);

	GameplayTags.Debuff_Wounded = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Wounded"),
		FString("Debuff for Physical Damage, as the Target sustains brutal injuries in battle")
		);

	GameplayTags.Debuff_Stun = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Stun"),
		FString("Debuff for Lightning Damage, ass the Target receives a paralyzing shock to their nervous system")
		);

	GameplayTags.Debuff_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Chance"),
		FString("Grants the chance a Debuff will accompany Damage during an attack in battle")
		);

	GameplayTags.Debuff_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Damage"),
		FString("Grants the amount of Damage that accumulates over a period of time if a Debuff occurs during an attack in battle")
		);

	GameplayTags.Debuff_Frequency = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Frequency"),
		FString("Grants how often a Debuff will inflict Damage on its Target during an attack in battle")
		);

	GameplayTags.Debuff_Duration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Debuff.Duration"),
		FString("Grants the length of time a Debuff will continue to inflict Damage on  its Target after an attack in battle")
		);

	/**
	 ** Meta Attributes
	 **/

	GameplayTags.Attributes_Meta_IncomingXP = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Meta.IncomingXP"),
	FString("Grants Ability to gain Levels through Experience Points")
	);

	 /*
	 ** Map of Damage Types to Resistances
	 */

	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Fire, GameplayTags.Attributes_Resistances_Fire);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Lightning, GameplayTags.Attributes_Resistances_Lightning);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Arcane, GameplayTags.Attributes_Resistances_Arcane);
	GameplayTags.DamageTypesToResistances.Add(GameplayTags.Damage_Physical, GameplayTags.Attributes_Resistances_Physical);

	/*
	** Map of Damage Types to Debuffs
	*/

	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Fire, GameplayTags.Debuff_Burn);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Lightning, GameplayTags.Debuff_Stun);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Arcane, GameplayTags.Debuff_Damned);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Physical, GameplayTags.Debuff_Wounded);

	 /*
	 ** Effects
	 */
	
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Effects.HitReact"),
		FString("Grants Ability to feel pain when one is injured in battle")
		);

	GameplayTags.Abilities_None = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.None"),
		FString("The mark designating that its Owner does not have, and may NEVER have, any Abilities")
		);

	/*
	** Abilities
	*/
	
	GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Attack"),
		FString("Grants Ability to attack your Enemies")
		);

	GameplayTags.Abilities_Summon = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Summon"),
		FString("Grants Ability to Summon Minions who do your bidding")
		);

	GameplayTags.Abilities_Status_Locked = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Status.Locked"),
		FString("Grants Ability to perceive potential future Abilities yet to be learned.")
		);

	GameplayTags.Abilities_Status_Eligible = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Status.Eligible"),
		FString("Grants Ability to learn a new or upgraded Ability")
		);

	GameplayTags.Abilities_Status_Unlocked = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Status.Unlocked"),
		FString("Grants the knowledge necessary to perform a new or upgraded Ability")
		);

	GameplayTags.Abilities_Status_Equipped = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Status.Equipped"),
		FString("Grants the User the Ability to perform a new or upgraded Ability in combat")
		);

	GameplayTags.Abilities_Type_Offensive = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Type.Offensive"),
		FString("Grants Ability to categorize any Ability as one used on offense in Combat")
		);

	GameplayTags.Abilities_Type_Passive = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Type.Passive"),
		FString("Grants Ability to categorize any Ability as one permanently affixed to the User, that doesn't require focus or concentration to be effective")
		);

	GameplayTags.Abilities_Type_None = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Type.None"),
		FString("Grants Ability to categorize any Ability that does not meet the requirements of either Offensive or Passive Abilities")
		);
	
	GameplayTags.Abilities_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Fire.FireBolt"),
		FString("Grants Ability to Conjure singular FireBolts from Aura's Staff to Burn Enemies")
		);

	GameplayTags.Abilities_Lightning_Electrocute = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Lightning.Electrocute"),
		FString("Grants Ability to Conjure singular Lightning Bolts from Aura's Staff to Electrocute Enemies")
		);

	/*
	** Passive Spells
	*/
	
	GameplayTags.Abilities_Passive_HaloOfProtection = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Passive.HaloOfProtection"),
		FString("Grants the User a Halo of Protection... duh!")
		);

	GameplayTags.Abilities_Passive_LifeSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Passive.LifeSiphon"),
		FString("Grants the User the Ability to Siphon Life... duh!")
		);

	GameplayTags.Abilities_Passive_ManaSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Abilities.Passive.ManaSiphon"),
		FString("Grants the User the Ability to Siphon Mana... you're a little slow, aren't you?")
		);

	/*
	** Cooldowns
	*/
	
	GameplayTags.Cooldown_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Cooldown.Fire.FireBolt"),
		FString("Grants Ability time to recharge before its next use")
		);

	/*
	** Combat Sockets
	*/
	
	GameplayTags.Combat_Socket_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Combat.Socket.Weapon"),
		FString("Grants Ability to socket a Weapon in your gear for combat")
		);

	GameplayTags.Combat_Socket_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Combat.Socket.LeftHand"),
		FString("Grants Ability to use your left hand as a weapon in combat")
		);

	GameplayTags.Combat_Socket_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Combat.Socket.RightHand"),
		FString("Grants Ability to use your right hand as a weapon in combat")
		);

	GameplayTags.Combat_Socket_Tail = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Combat.Socket.Tail"),
		FString("Grants Ability to use your tail as a weapon in combat")
		);

	/*
	** Montages
	*/
	
	GameplayTags.Montage_Attack_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Montage.Attack.1"),
		FString("Because even in Combat... you want to look good.")
		);

	GameplayTags.Montage_Attack_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Montage.Attack.2"),
		FString("Because even in Combat... you want to look good when you know two different attack moves.")
		);

	GameplayTags.Montage_Attack_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Montage.Attack.3"),
		FString("Because even in Combat... you want to look good with all three of the attack moves at your disposal.")
		);

	GameplayTags.Montage_Attack_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Montage.Attack.4"),
		FString("Because even in Combat... you want to look good when you blow enemies away with the four unique attack moves you've mastered in such a short amount of time.")
		);

	/*
	** Player Tags
	*/
	
	GameplayTags.Player_Block_InputPressed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Player.Block.InputPressed"),
		FString("Stops the Player from pressing one ability key while another one is already in use." )
		);

	GameplayTags.Player_Block_InputHeld = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("PLayer.Block.InputHeld"),
		FString("Stops the Player from holding one ability key while another one is already in use.")
		);

	GameplayTags.Player_Block_InputReleased = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Player.Block.InputReleased"),
		FString("Stops the Player from releasing one ability key while another one is already in use.")
		);

	GameplayTags.Player_Block_CursorTrace = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Player.Block.CursorTrace"),
		FString("Stops the Player from tracing under the cursor to highlight enemies targeted.")
		);
}
