export class DnDCharacter {
  public strength: number;
  public dexterity: number;
  public constitution: number;
  public intelligence: number;
  public wisdom: number;
  public charisma: number;

  public hitpoints: number;

  constructor() {
    this.strength = DnDCharacter.generateAbilityScore();
    this.dexterity = DnDCharacter.generateAbilityScore();
    this.constitution = DnDCharacter.generateAbilityScore();
    this.intelligence = DnDCharacter.generateAbilityScore();
    this.wisdom = DnDCharacter.generateAbilityScore();
    this.charisma = DnDCharacter.generateAbilityScore();


    this.hitpoints = 10 + DnDCharacter.getModifierFor(this.constitution);
  }

  public static generateAbilityScore(): number {
    const dice = [...Array(6)].map(() => 1 + Math.floor(Math.random() * 6));
    dice.sort();
    return dice.slice(3,6).reduce((carry,el) => carry + el, 0);
  }

  public static getModifierFor(abilityValue: number): number {
    return Math.floor(abilityValue / 2)  - 5;
  }
}
