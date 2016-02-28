import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */

public class football {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    Task solver = new Task();
    solver.solve(1, in, out);
    out.close();
  }
}

class Task { 
  String[] s;
  public void solve(int testNumber, InputReader in, PrintWriter out) {
    int n = in.nextInt();
    s = new String[n];
    for(int i = 0; i < n; i++) {
      s[i] = in.next();
    }
    Arrays.sort(s);
    int f = 0;
    for(int i = 1; i < n; i++) {
      if(s[i].equals(s[i - 1])) {
        f = i;
      } else {
        break;
      }
    }
    f++;
    int sec = n - f;
    if(f > sec) {
      out.println(s[0]);
    } else {
      out.println(s[n - 1]);
    }
  }
}

class InputReader {
  public BufferedReader reader;
  public StringTokenizer tokenizer;

  public InputReader(InputStream stream) {
    reader = new BufferedReader(new InputStreamReader(stream), 32768);
    tokenizer = null;
  }

  public String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  public int nextInt() {
    return Integer.parseInt(next());
  }

  public long nextLong() {
    return Long.parseLong(next());
  }
	
  public double nextDouble() {
    return Double.parseDouble(next());
  }
}