export class Clock {
  protected minutes: number;
  static readonly MINUTES_PER_DAY: number  = 24 * 60;
  constructor(hour: number = 0, minute: number = 0) {
    this.minutes = 0;
    this.addMinutes(60 * hour + minute);
  }

  protected addMinutes(minutes: number) {
    this.minutes += minutes;
    this.minutes %= Clock.MINUTES_PER_DAY;
    console.log(this.minutes);
    if (this.minutes < 0) {
      this.minutes += Clock.MINUTES_PER_DAY;
    }
  }

  public hour(): number {
    return Math.floor(this.minutes / 60);
  }

  public minute(): number {
    return this.minutes % 60;
  }

  public toString(): string {
    return `${this.hour().toString().padStart(2, '0')}:${this.minute().toString().padStart(2, '0')}`;

  }

  public plus(minutes: number): Clock {
    return new Clock(0, this.minutes + minutes);
  }

  public minus(minutes: number): Clock {
    return new Clock(0, -1 * minutes + this.minutes);
  }

  public equals(other: Clock): boolean {
    return this.toString() == other.toString();
  }
}
