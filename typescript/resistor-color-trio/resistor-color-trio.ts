
const colorValues = {
  black: 0,
  brown: 1,
  red: 2,
  orange: 3,
  yellow: 4,
  green: 5,
  blue: 6,
  violet: 7,
  grey: 8,
  white: 9,
}

export function decodedValue([color1, color2]: (keyof typeof colorValues)[]): number {
  return 10 * colorValues[color1] + colorValues[color2];
}

export function decodedResistorValue([color1, color2, color3]: (keyof typeof colorValues)[]): string {
  let value: number = decodedValue([color1, color2]);
  let magnitude: number = colorValues[color3];
  if (value % 10 == 0) {
    magnitude += 1;
    value /= 10;
  }
  value *= 10 ** (magnitude % 3);
  let unit: string;
  switch (Math.floor(magnitude / 3)) {
    case 0:
      unit = 'ohms';
    break;
    case 1:
      unit = 'kiloohms';
    break;
    case 2:
      unit = 'megaohms';
    break;
    case 3:
      unit = 'gigaohms';
    break;
    default:
      throw "ARgghh";
  }

  return value + " " + unit;
}

