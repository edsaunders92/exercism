type Opt<T> = T | null;

class Node<T> {
  public value: T;
  public next: Opt<Node<T>>;
  public prev: Opt<Node<T>>;

  constructor(value: T, next: Opt<Node<T>> = null, prev: Opt<Node<T>> = null) {
    this.value = value;
    this.prev = prev;
    this.next = next;
  }
}

export class LinkedList<T> {

  private head : Opt<Node<T>> = null;
  private tail: Opt<Node<T>> = null;
  private _count: number = 0;

  public pop(): T {
    if (!this.tail) {
      throw new Error();
    }
    const node = this.tail;
    if (!node.prev) {
      this.tail = null;
      this.head = null;
    } else {
      this.tail = node.prev;
      this.tail.next = null;
    }

    this._count--;
    return node.value;
  }


  public shift(): T {
    if (!this.head) {
      throw new Error();
    }
    const node = this.head;
    if (!node.next) {
      this.tail = null;
      this.head = null;
    } else {
      this.head = node.next;
      this.head.prev = null;
    }

    this._count--;
    return node.value;
  }

  public push(element: T) {
    const node: Node<T> = new Node<T>(element);
    this._count++;
    if (!this.tail) {
      this.head = node;
      this.tail = node;
      return;
    }
    this.tail.next = node;
    node.prev = this.tail;
    this.tail = node;
  }

  public unshift(element: T) {
    const node: Node<T> = new Node<T>(element);
    this._count++;
    if (!this.head) {
      this.head = node;
      this.tail = node;
      return;
    }
    this.head.prev = node;
    node.next = this.head;
    this.head = node;
  }

  public delete(element: T) {
    let node: Opt<Node<T>> = this.head;
    while (node) {
      console.log(node.value, element);
      if (node.value == element) {
        this._count--;
        if (node === this.tail && node === this.head) {
          this.tail = null
          this.head = null
        } else if (!node.next) {
          this.pop();
        } else if (!node.prev) {
          this.shift();
        } else {
          node.prev.next = node.next;
          node.next.prev= node.prev;
        }
        break;
      }
      node = node.next;
    }
  }

  public count(): Number {
    return this._count;
  }
}
