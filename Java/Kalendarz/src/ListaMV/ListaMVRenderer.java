package ListaMV;

import javax.swing.*;
import java.awt.*;

public class ListaMVRenderer extends JLabel implements ListCellRenderer {
    @Override
    public Component getListCellRendererComponent(JList jList, Object o, int i, boolean b, boolean b1) {
        setText(o.toString());
        String splitted[] = getText().split(" ");
        if (splitted[1].equals("Niedziela"))
            setForeground(Color.red);
        else
            setForeground(Color.black);
        return this;
    }

    {
// GUI initializer generated by IntelliJ IDEA GUI Designer
// >>> IMPORTANT!! <<<
// DO NOT EDIT OR ADD ANY CODE HERE!
        $$$setupUI$$$();
    }

    /**
     * Method generated by IntelliJ IDEA GUI Designer
     * >>> IMPORTANT!! <<<
     * DO NOT edit this method OR call it in your code!
     *
     * @noinspection ALL
     */
    private void $$$setupUI$$$() {
        final JPanel panel1 = new JPanel();
        panel1.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
    }
}
