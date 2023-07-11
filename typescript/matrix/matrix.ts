export class Matrix {
  protected matrix: number[][];

  constructor(matrix: string) {
    console.log(matrix.split('\n').map((row) => (row).split(' ')));
    this.matrix = matrix.split('\n').map((row) => (row).split(' ').map(Number));
  }

  get rows(): number[][] {
    return this.matrix;
  }

  get columns(): number[][] {
    const transpose: number[][] = [];
    for (let j: number = 0; j < this.matrix[0].length; j++ ) {
      transpose.push([]);
      for (let i: number = 0; i < this.matrix.length; i++ ) {
        transpose[j].push(this.matrix[i][j]);
      }
    }
    return transpose;
  }
}
