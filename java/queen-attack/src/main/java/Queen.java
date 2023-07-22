public class Queen implements Cloneable {
  protected int rank;
  protected int file;

  public Queen(int rank, int file) {
    this.rank = rank;
    this.file = file;

    if (this.rank < 0) {
      throw new IllegalArgumentException("Queen position must have positive row.");
    }
    if (this.file < 0) {
      throw new IllegalArgumentException("Queen position must have positive column.");
    }
    if (this.rank >= 8) {
      throw new IllegalArgumentException("Queen position must have row <= 7.");
    }
    if (this.file >= 8) {
      throw new IllegalArgumentException("Queen position must have column <= 7.");
    }
  }

  public boolean isValid() {
    return this.rank >= 0 && this.rank < 8 && this.file >= 0 && this.file < 8;
  }

  public void move(int delta_file, int delta_rank) {
    this.file += delta_file;
    this.rank += delta_rank;
  }

  public Queen duplicate() {
      return new Queen(this.rank, this.file);
  }

  @Override
  public boolean equals(Object o) {

    if (!(o instanceof Queen)) {
      return false;
    }

    Queen otherQueen  = (Queen) o;

    // Compare the data members and return accordingly
    return this.rank == otherQueen.rank && this.file == otherQueen.file;
  }
}
