/** 
 * Given a year, report if it is a leap year.
 */
export function isLeap(year: number): boolean {
  return !! (!(year % 4) && (((year%100)) || !(year % 400)));
}
