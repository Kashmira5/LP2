import java.util.Scanner;

public class ElementaryChatbot {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("WelCome To Edubot - Your Admission Assistant!");
    System.out.println("Type 'Exit' anytime to end the chat.\n");

    while(true) {
      System.out.println("You: ");
      String input = scanner.nextLine().toLowerCase();

      if(input.contains("Exit") || input.contains("exit") || input.contains("Bye") || input.contains("bye") ||) {
        System.out.println("EduBot: Thank you for your interest! All the best for your future!");
        break;
      }
      else if((input.contains("courses") || input.contains("programs") || input.contains("offer")) {
        System.out.println("EduBot: We offer B.Tech, B.E., BBA, BCA, MBA, and MCA programs.");
      }
      else if((input.contains("admissions") || input.contains("process") || input.contains("apply")) {
        System.out.println("EduBot: You can apply online through our official website. The process includes registration, document upload, and payment of application fees.");
      }
      else if(input.contains("eligibility") || input.contains("criteria")) {
        System.out.println("EduBot: For UG courses, you need a minimum of 50% in 12th class. For PG, a relevant bachelor's degree is required.");
      }
      else if((input.contains("fees") || input.contains("fees structure") || input.contains("tuition")) {
        System.out.println("EduBot: The tuition fees varies by course. For B.Tech/B.E., it's 1.16L per year. You can find full details on our website.");
      }
      else if((input.contains("contact") || input.contains("phone") || input.contains("email")) {
        System.out.println("EduBot: You can contact us at +91 123123123 or email us at: adm@xyzuni.ac.in");
      }
      else() {
        System.out.println("EduBot: I'm sorry, I didn't understand that. Could you please rephrase?");
      }
    }
    scanner.close();
  }
}
