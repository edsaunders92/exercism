export class List {
  public values: any[];

  constructor(values: any[]) {
    this.values = values;
  }

  public static create(...values: any): List {
    return new List(values);
  }

  append(other: List): List {
    return List.create(...this.values, ...other.values);
  }

  concat(others: List): this {
    throw new Error('Remove this statement and implement this function')
  }

  filter<T>(fn: (el: T) => Boolean): this {

  }

  map<T>(fn: (el: T) => T): this {
    throw new Error('Remove this statement and implement this function')
  }

  foldl<T, S>(fn: (el: T, acc: S) => S, acc: S ): S {
    throw new Error('Remove this statement and implement this function')
  }

  foldr<T, S>(fn: (el: T, acc: S) => S, acc: S ): S {
    throw new Error('Remove this statement and implement this function')
  }

  reverse(): this {
    throw new Error('Remove this statement and implement this function')
  }

  length(): number {
    throw new Error('Remove this statement and implement this function')
  }

  forEach(fn: (el: any) => any) {
    throw new Error('Remove this statement and implement this function')
  }
}
