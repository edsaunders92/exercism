export class Gigasecond {
  private _date: Date;

  constructor(date: Date) {
    this._date = new Date(date.getTime() + 1_000_000_000_000);
  }

  public date(): Date {
    return this._date;
  }
}
