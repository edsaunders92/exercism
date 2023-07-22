public class QueenAttackCalculator {

  protected Queen whiteQueen;
  protected Queen blackQueen;

  public QueenAttackCalculator(Queen whiteQueen, Queen blackQueen) {
    this.whiteQueen = whiteQueen;
    this.blackQueen = blackQueen;

    if ((whiteQueen == null) || (blackQueen == null)) {
      throw new IllegalArgumentException("You must supply valid positions for both Queens.");
    }

    if (whiteQueen.equals(blackQueen)) {
      throw new IllegalArgumentException("Queens cannot occupy the same position.");
    }
  }

  public boolean canQueensAttackOneAnother() {
    for (int dFile = -1; dFile <= 1; dFile++) {
      for (int dRank = -1; dRank <= 1; dRank++) {
        if (dRank == 0 && dFile == 0) {
          continue;
        }
        Queen queen = this.whiteQueen.duplicate();

        while (queen.isValid()) {
          if (this.blackQueen.equals(queen)) {
            return true;
          }
          queen.move(dFile, dRank);
        }
      }
    }
    return false;
  }
}

