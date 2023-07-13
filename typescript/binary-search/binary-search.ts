export function find(haystack: number[], needle: number): number | never {
  let left: number = 0;
  let right: number = haystack.length - 1;
  while (left <= right) {
    let mid = Math.floor((right + left) / 2);
    let diff = haystack[mid] - needle;
    if (diff == 0) {
      return mid;
    } else if (diff < 0) {
      left = mid + 1
    } else {
      right = mid - 1
    }
  }
  throw new Error('Value not in array');
}
