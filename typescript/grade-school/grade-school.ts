function deepCopy<T>(obj: T): T{
  return JSON.parse(JSON.stringify(obj));
}
export class GradeSchool {

  protected _roster: { [id: number]: string[] };
  protected _students: { [id:string]: number };

  constructor() {
    this._roster = {};
    this._students = {};
  }

  roster(): { [id: number]: string[] } {
    return deepCopy(this._roster);
  }

  add(firstName: string, grade: number) {
    if (!(grade in this._roster)) {
      this._roster[grade] = [];
    }

    if (firstName in this._students) {
      const oldGrade = this._students[firstName];
      const index = this._roster[oldGrade].findIndex((student) => student === firstName);
      this._roster[oldGrade].splice(index, 1);
    }

    this._students[firstName] = grade;
    this._roster[grade].push(firstName);
    this._roster[grade].sort();
  }

  grade(grade: number): string[] {
    return (grade in this._roster) ? deepCopy(this._roster[grade]) : [];
  }
}
