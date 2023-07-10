export function score(x: number, y: number): number {
  const r = Math.sqrt(x*x + y*y);

  if (r <= 1) {
    return 10;
  }

  if (r <= 5) {
    return 5;
  }

  if (r <= 10) {
    return 1;
  }

  return 0;
}
