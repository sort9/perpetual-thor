import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileParser {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("extraction.log"));
            FileWriter writer = new FileWriter("parser_output.csv");

            // Skip the first 6 lines
            for (int i = 0; i < 6; i++) {
                if (scanner.hasNextLine()) {
                    scanner.nextLine(); // Skip the line
                }
            }

            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] data = line.trim().split("\\s+"); // Split by one or more spaces
                String csvLine = String.join(",", data);   // Join the array with commas
                writer.append(csvLine).append("\n");        // Write to CSV file
            }

            scanner.close();
            writer.close();
            System.out.println("Data has been written to parser_output.csv");

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
