package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node {
	char data;
	Node left;
	Node right;

	public Node(char data) {
		this.data = data;
	}
}

class Tree {
	public Node root;

	public Tree(char data, char left, char right) {
		// root = new Node(data);

		if (data != '.') // .�� �ƴϸ� ��� ���� �� ������ ����
			root = new Node(data);
		if (left != '.') // . �� �ƴϸ� ��� ������ ������ ����
			root.left = new Node(left);
		if (right != '.') // .�� �ƴϸ� ��� ������ ������ ����
			root.right = new Node(right);
	}

	/*
	 * public void setRoot(Node node) { this.root = node; }
	 * 
	 * public Node getRoot() { return root; }
	 */

	public void add(char data, char left, char right) {
		next(root.left, data, left, right);
		next(root.right, data, left, right);
	}

	public void next(Node node, char data, char left, char right) {
		if (node == null) // ��尡 null�̸� ����.
			return;

		// .�� �ƴϸ� ���ʳ�� �����ʳ�� ������ ������ ����
		else if (node.data == data) {
			if (left != '.')
				node.left = new Node(left);
			if (right != '.')
				node.right = new Node(right);
			// Ž���� ������ �����ִ� ���
		} else {
			next(node.left, data, left, right); // ���� Ž��
			next(node.right, data, left, right); // ������ Ž��
		}
	}

	/*
	 * public Node makeTree(Node left, char data, Node right) { Node node = new
	 * Node(); node.data = data; node.left = left; node.right = right; return node;
	 * }
	 */

	public void preorder(Node node) { // ������ȸ:��Ʈ -> �����ڽ� -> �������ڽ�
		if (node != null) {
			System.out.print(node.data);
			if (node.left != null) {
				preorder(node.left);
			}
			if (node.right != null) {
				preorder(node.right);
			}

		}
	}

	public void inorder(Node node) { // ������ȸ: �����ڽ� -> ��Ʈ -> ������ �ڽ�
		if (node != null) {
			if (node.left != null) {
				inorder(node.left);
			}
			System.out.print(node.data);
			if (node.right != null) {
				inorder(node.right);
			}

		}
	}

	public void postorder(Node node) { // ������ȸ : �����ڽ� -> �������ڽ� -> ��Ʈ
		if (node != null) {
			if (node.left != null) {
				postorder(node.left);
			}
			if (node.right != null) {
				postorder(node.right);
			}
			System.out.print(node.data);

		}
	}
}

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		// replaceAll(" ", "")�� ������ readLine���� �о���� ���ڿ����� ���⸦ �����ϰ� toCharArray()�� ����
		// �ϳ� �ϳ��� char�� ���� ó��
		char[] data = in.readLine().replaceAll(" ", "").toCharArray();

		Tree t = new Tree(data[0], data[1], data[2]);

		for (int i = 1; i < n; i++) {
			data = in.readLine().replaceAll(" ", "").toCharArray();
			t.add(data[0], data[1], data[2]);
		}

		t.preorder(t.root);
		System.out.println();
		t.inorder(t.root);
		System.out.println();
		t.postorder(t.root);

		/*
		 * for(int i = 0; i<=n; i++) { String words = sc.nextLine(); }
		 */

	}
}

