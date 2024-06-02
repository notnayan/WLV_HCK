import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JScrollPane;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JTable;

import com.mysql.cj.api.mysqla.result.Resultset;

import javax.swing.JEditorPane;
import javax.swing.table.DefaultTableModel;

public class NayanRajKhanal_2227486 {

	private JFrame frame;
	private JTable table;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					NayanRajKhanal_2227486 window = new NayanRajKhanal_2227486();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public NayanRajKhanal_2227486() {
		initialize();
	}
	
	class User {
		private int id;
		private String firstName;
		private String lastName;

		public User(int id, String firstName, String lastName) {
			this.id = id;
			this.firstName = firstName;
			this.lastName = lastName;
		}

		public int getId() {
			return id;
		}

		public String getFirstName() {
			return firstName;
		}

		public String getLastName() {
			return lastName;
		}
	}
	
	public String[][] fetch() {
		String userData[][] = null;	
		try {
			
            Class.forName("com.mysql.cj.jdbc.Driver");
			String url="jdbc:mysql://localhost:3306";
			String username="root";
			String password="";
			
			Connection con=DriverManager.getConnection(url,username,password);
			
			String c="CREATE DATABASE classwork";
			String u="USE classwork";
			String t="CREATE TABLE herald(firstName varchar(25),lastName varchar(25),ID int PRIMARY KEY AUTO_INCREMENT)";
			String q="INSERT INTO herald(firstName,lastName) VALUES(?,?)";
			String p="SELECT * FROM herald";
				
			//database creation
			try {
				Statement stmt= con.createStatement();
				stmt.executeUpdate(c);
			} catch (SQLException e) {
				if (e.getErrorCode() == 1007)
					System.out.println("Database exists!");
				else
					throw e;
			}
			Statement stmt2= con.createStatement();
			stmt2.executeUpdate(u);
			
			//table creation
			try {
				Statement stmt3= con.createStatement();
				stmt3.executeUpdate(t);
			} catch (SQLException e) {
				if (e.getErrorCode() == 1050)
					System.out.println("Table exists!");
				else
					throw e;
			}
			
			PreparedStatement pstmt =con.prepareStatement(q);
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter fname: ");
			String fname=sc.nextLine();
			System.out.println("Enter lname: ");
			String lname=sc.nextLine();
			
			pstmt.setString(1, fname);
			pstmt.setString(2, lname);
			pstmt.executeUpdate();
			
			PreparedStatement pstmt2 =con.prepareStatement(p);
			ArrayList<User> users = new ArrayList<User>();
			try {
				ResultSet rs = pstmt2.executeQuery(p);
				while (rs.next()) {
					int id = rs.getInt(3);
					String firstName = rs.getString("firstName");
					String lastName = rs.getString("lastName");
					User user = new User(id, firstName, lastName);
					users.add(user);
				}
			} catch (SQLException ee) {
				ee.printStackTrace();
			}

			userData= new String[users.size()][3];
			for (int i = 0; i < users.size(); i++) {
				User user = users.get(i);
				userData[i][0] = Integer.toString(user.getId());
				userData[i][1] = user.getFirstName();
				userData[i][2] = user.getLastName();
			}
			
			sc.close();
			con.close();
			
		} catch (Exception e) {
			JOptionPane.showMessageDialog(null, e);
		}
		return userData;
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 502, 396);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("HERALD APP");
		lblNewLabel.setBounds(10, 11, 163, 41);
		lblNewLabel.setFont(new Font("Inter", Font.BOLD, 25));
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Sign Up");
		lblNewLabel_1.setBounds(347, 30, 46, 14);
		frame.getContentPane().add(lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("Sign In");
		lblNewLabel_2.setBounds(403, 30, 46, 14);
		frame.getContentPane().add(lblNewLabel_2);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(10, 94, 466, 252);
		frame.getContentPane().add(scrollPane_1);
		
		table = new JTable();
		String[][] userData= fetch();
		scrollPane_1.setViewportView(table);
		table.setModel(new DefaultTableModel(
			userData,
			new String[] {
				"ID", "First Name", "Last Name"
			}
		));
	}
}
