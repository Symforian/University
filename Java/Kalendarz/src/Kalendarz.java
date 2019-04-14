import javax.swing.*;
import java.awt.*;
import java.util.Calendar;
import java.util.GregorianCalendar;
import ListaMV.*;
import KonwersjaDanych.KonwerterGCalend;


public class Kalendarz {


    private JTabbedPane RMtabbedPane;
    private JPanel MainPanel;
    private JPanel RokPanel;
    private JPanel MiesiacPanel;
    private JToolBar MyToolBar;
    private JList MiesiacWybrany;
    private JList MiesiacPoprzedni;
    private JList MiesiacNastepny;
    private ListaM W;
    private ListaM P;
    private ListaM N;
    private JButton Dzis;
    private JSpinner Rokspinner;
    private JButton IdzDo;
    private JLabel MiesiacPNazwa;
    private JLabel MiesiacWNazwa;
    private JLabel MiesiacNNazwa;
    private JButton styczeńButton;
    private JButton lutyButton;
    private JButton marzecButton;
    private JButton czerwiecButton;
    private JButton kwiecieńButton;
    private JButton majButton;
    private JButton lipiecButton;
    private JButton sierpieńButton;
    private JButton wrzesieńButton;
    private JButton październikButton;
    private JButton listopadButton;
    private JButton grudzieńButton;
    private JLabel m1;
    private JLabel m2;
    private JLabel m3;
    private JLabel m4;
    private JLabel m5;
    private JLabel m6;
    private JLabel m7;
    private JLabel m8;
    private JLabel m9;
    private JLabel m10;
    private JLabel m11;
    private JLabel m12;
    private JComboBox MiesComb;
    private GregorianCalendar Calend;
    private JLabel[] MiesKale;
    private JButton[] KaleButtons;


    public Kalendarz() {
        //super("Kalendarz");

        createArrayForMiesKale();
        createArrayForKaleButtons();


        addOptionsToCombobox();

        Dzis.addActionListener(e -> {
            Calend = new GregorianCalendar();
            RMtabbedPane.setTitleAt(0, String.valueOf(Calend.get(Calendar.YEAR)));
            RMtabbedPane.setTitleAt(1, KonwerterGCalend.NumbToMonth(Calend.get(Calendar.MONTH)));
            MiesComb.setSelectedIndex(Calend.get(Calendar.MONTH));
            Rokspinner.setModel(new SpinnerNumberModel(Calend.get(Calendar.YEAR), -2500, 9000, 1));
            setLists(Calend.get(Calendar.YEAR), Calend.get(Calendar.MONTH));
            fixYearCal();

        });

        Dzis.doClick();
        RMtabbedPane.setSelectedIndex(1);
        IdzDo.addActionListener(e -> {

            if (Calend.get(Calendar.YEAR) == (int) Rokspinner.getValue()) {
            } else {
                Calend.set((int) Rokspinner.getValue(), Calend.get(Calendar.MONTH), 1);
                Rokspinner.setModel(new SpinnerNumberModel(Calend.get(Calendar.YEAR), -2500, 9000, 1));

                RMtabbedPane.setTitleAt(0, String.valueOf(Calend.get(Calendar.YEAR)));

                fixYearCal();
                setLists(Calend.get(Calendar.YEAR), Calend.get(Calendar.MONTH));
            }
            if (Calend.get(Calendar.MONTH) == KonwerterGCalend.MonthToNumb(MiesComb.getSelectedItem().toString())) {
            } else {
                Calend.set(Calend.get(Calendar.YEAR), KonwerterGCalend.MonthToNumb(MiesComb.getSelectedItem().toString()), 1);
                RMtabbedPane.setTitleAt(1, KonwerterGCalend.NumbToMonth(Calend.get(Calendar.MONTH)));
                setLists(Calend.get(Calendar.YEAR), Calend.get(Calendar.MONTH));
            }

        });
        for (int i = 0; i < 12; i++) {
            final int ii = i;
            KaleButtons[i].addActionListener(e -> ButtonYearCalend(ii));
        }
        Rokspinner.setModel(new SpinnerNumberModel(Calend.get(Calendar.YEAR), -2500, 9000, 1));


    }

    private void setLists(int year, int month) {
        setList(-1, year, month - 1);
        setList(0, year, month);
        setList(1, year, month + 1);
    }

    private void setList(int which, int year, int month) {
        if (which == -1) {
            if (month == -1) {
                year--;
                month = 11;
            }
            MiesiacPNazwa.setText("<html>" + year + "<br>" + KonwerterGCalend.NumbToMonth(month) + "</html>");
            P = new ListaM(year, month);
            MiesiacPoprzedni.setModel(P);
            MiesiacPoprzedni.setCellRenderer(new ListaMVRenderer());
            P.add();

        }
        if (which == 0) {
            MiesiacWNazwa.setText("<html>" + year + "<br>" + KonwerterGCalend.NumbToMonth(month) + "</html>");
            W = new ListaM(year, month);
            MiesiacWybrany.setModel(W);
            MiesiacWybrany.setCellRenderer(new ListaMVRenderer());
            W.add();
        }
        if (which == 1) {
            if (month == 12) {
                year++;
                month = 0;
            }
            MiesiacNNazwa.setText("<html>" + year + "<br>" + KonwerterGCalend.NumbToMonth(month) + "</html>");
            N = new ListaM(year, month);
            MiesiacNastepny.setModel(N);

            MiesiacNastepny.setCellRenderer(new ListaMVRenderer());
            N.add();
        }
    }

    private void ButtonYearCalend(int i) {
        setLists(Calend.get(Calendar.YEAR), i);
        RMtabbedPane.setTitleAt(1, KonwerterGCalend.NumbToMonth(i));
        RMtabbedPane.setSelectedIndex(1);

    }

    private void createArrayForKaleButtons() {
        KaleButtons = new JButton[12];
        KaleButtons[0] = styczeńButton;
        KaleButtons[1] = lutyButton;
        KaleButtons[2] = marzecButton;
        KaleButtons[3] = kwiecieńButton;
        KaleButtons[4] = majButton;
        KaleButtons[5] = czerwiecButton;
        KaleButtons[6] = lipiecButton;
        KaleButtons[7] = sierpieńButton;
        KaleButtons[8] = wrzesieńButton;
        KaleButtons[9] = październikButton;
        KaleButtons[10] = listopadButton;
        KaleButtons[11] = grudzieńButton;

    }

    private void createArrayForMiesKale() {
        MiesKale = new JLabel[12];
        MiesKale[0] = m1;
        MiesKale[1] = m2;
        MiesKale[2] = m3;
        MiesKale[3] = m4;
        MiesKale[4] = m5;
        MiesKale[5] = m6;
        MiesKale[6] = m7;
        MiesKale[7] = m8;
        MiesKale[8] = m9;
        MiesKale[9] = m10;
        MiesKale[10] = m11;
        MiesKale[11] = m12;
    }

    private void addOptionsToCombobox() {

        for (int i = 0; i < 12; i++)
            MiesComb.addItem(KonwerterGCalend.NumbToMonth(i));

    }

    private void fixYearCal() {
        int m = Calend.get(Calendar.MONTH);
        int d = Calend.get(Calendar.DAY_OF_MONTH);
        int y = Calend.get(Calendar.YEAR);
        for (int i = 0; i < 12; i++) {
            String card = "<html><pre><font color=\"black\"> Pn Wt Śr Cz Pt Sb </font><font color=\"red\">Nd<br></font></pre><font color=\"black\"><pre>";
            Calend.set(y, i, d);
            for (int dzien = 1; dzien <= Calend.getActualMaximum(Calendar.DAY_OF_MONTH); dzien++) {
                if (y == 1582 && i == Calendar.OCTOBER && dzien == 5) {
                    dzien = 14;
                    continue;
                }
                Calend.set(y, i, dzien);

                if (dzien == 1) {
                    int buf = Calend.get(Calendar.DAY_OF_WEEK);

                    if (buf == Calendar.SUNDAY)
                        buf = 8;
                    for (int j = Calendar.MONDAY; j < buf; j++)
                        card += "   ";
                    card += " ";

                } else
                    card += " ";
                if (dzien < 10)
                    card += " ";
                if (Calend.get(Calendar.DAY_OF_WEEK) == 1)
                    card += "</font><font color=\"red\">" + dzien + "</font><font color=\"black\"><br>";
                else
                    card += dzien;


            }
            card += "</pre></font></html>";
            MiesKale[i].setText(card);

        }
        Calend.set(y, m, d);
    }


    public static void main(String[] args) {
        JFrame frame = new JFrame("Kalendarz");
        frame.setContentPane(new Kalendarz().MainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.pack();
        frame.setVisible(true);


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
        MainPanel = new JPanel();
        MainPanel.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(2, 1, new Insets(0, 0, 0, 0), -1, -1));
        RMtabbedPane = new JTabbedPane();
        MainPanel.add(RMtabbedPane, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, new Dimension(200, 200), null, 0, false));
        RokPanel = new JPanel();
        RokPanel.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(8, 3, new Insets(0, 0, 0, 0), -1, -1));
        RMtabbedPane.addTab("Rok", RokPanel);
        final JPanel panel1 = new JPanel();
        panel1.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel1, new com.intellij.uiDesigner.core.GridConstraints(1, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m1 = new JLabel();
        m1.setText("<html><pre>    01  02  03  04  05  06  07<br> 08  09 10 11 12 13 <font color=\"red\">14</font><br> 15 16 17 18 19 20 21<br>22 23 24 25 26 27 28<br>29 30 31</pre></html>");
        panel1.add(m1, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        styczeńButton = new JButton();
        styczeńButton.setText("Styczeń");
        RokPanel.add(styczeńButton, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        lutyButton = new JButton();
        lutyButton.setText("Luty");
        RokPanel.add(lutyButton, new com.intellij.uiDesigner.core.GridConstraints(0, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        marzecButton = new JButton();
        marzecButton.setText("Marzec");
        RokPanel.add(marzecButton, new com.intellij.uiDesigner.core.GridConstraints(0, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel2 = new JPanel();
        panel2.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel2, new com.intellij.uiDesigner.core.GridConstraints(1, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m2 = new JLabel();
        m2.setText("Label");
        panel2.add(m2, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel3 = new JPanel();
        panel3.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel3, new com.intellij.uiDesigner.core.GridConstraints(1, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m3 = new JLabel();
        m3.setText("Label");
        panel3.add(m3, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        czerwiecButton = new JButton();
        czerwiecButton.setText("Czerwiec");
        RokPanel.add(czerwiecButton, new com.intellij.uiDesigner.core.GridConstraints(2, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        kwiecieńButton = new JButton();
        kwiecieńButton.setText("Kwiecień");
        RokPanel.add(kwiecieńButton, new com.intellij.uiDesigner.core.GridConstraints(2, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        majButton = new JButton();
        majButton.setText("Maj");
        RokPanel.add(majButton, new com.intellij.uiDesigner.core.GridConstraints(2, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel4 = new JPanel();
        panel4.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel4, new com.intellij.uiDesigner.core.GridConstraints(3, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m4 = new JLabel();
        m4.setText("m4");
        panel4.add(m4, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel5 = new JPanel();
        panel5.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel5, new com.intellij.uiDesigner.core.GridConstraints(3, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m5 = new JLabel();
        m5.setText("Label");
        panel5.add(m5, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel6 = new JPanel();
        panel6.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel6, new com.intellij.uiDesigner.core.GridConstraints(3, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m6 = new JLabel();
        m6.setText("Label");
        panel6.add(m6, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        lipiecButton = new JButton();
        lipiecButton.setText("Lipiec");
        RokPanel.add(lipiecButton, new com.intellij.uiDesigner.core.GridConstraints(4, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        sierpieńButton = new JButton();
        sierpieńButton.setText("Sierpień");
        RokPanel.add(sierpieńButton, new com.intellij.uiDesigner.core.GridConstraints(4, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        wrzesieńButton = new JButton();
        wrzesieńButton.setText("Wrzesień");
        RokPanel.add(wrzesieńButton, new com.intellij.uiDesigner.core.GridConstraints(4, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel7 = new JPanel();
        panel7.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel7, new com.intellij.uiDesigner.core.GridConstraints(5, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m7 = new JLabel();
        m7.setText("Label");
        panel7.add(m7, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel8 = new JPanel();
        panel8.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel8, new com.intellij.uiDesigner.core.GridConstraints(5, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m8 = new JLabel();
        m8.setText("Label");
        panel8.add(m8, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel9 = new JPanel();
        panel9.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel9, new com.intellij.uiDesigner.core.GridConstraints(5, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m9 = new JLabel();
        m9.setText("Label");
        panel9.add(m9, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        październikButton = new JButton();
        październikButton.setText("Październik");
        RokPanel.add(październikButton, new com.intellij.uiDesigner.core.GridConstraints(6, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        listopadButton = new JButton();
        listopadButton.setText("Listopad");
        RokPanel.add(listopadButton, new com.intellij.uiDesigner.core.GridConstraints(6, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        grudzieńButton = new JButton();
        grudzieńButton.setText("Grudzień");
        RokPanel.add(grudzieńButton, new com.intellij.uiDesigner.core.GridConstraints(6, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel10 = new JPanel();
        panel10.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel10, new com.intellij.uiDesigner.core.GridConstraints(7, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m10 = new JLabel();
        m10.setText("Label");
        panel10.add(m10, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel11 = new JPanel();
        panel11.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel11, new com.intellij.uiDesigner.core.GridConstraints(7, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m11 = new JLabel();
        m11.setText("Label");
        panel11.add(m11, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JPanel panel12 = new JPanel();
        panel12.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(1, 1, new Insets(0, 0, 0, 0), -1, -1));
        RokPanel.add(panel12, new com.intellij.uiDesigner.core.GridConstraints(7, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_GROW, null, null, null, 0, false));
        m12 = new JLabel();
        m12.setText("Label");
        panel12.add(m12, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_WEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        MiesiacPanel = new JPanel();
        MiesiacPanel.setLayout(new com.intellij.uiDesigner.core.GridLayoutManager(2, 3, new Insets(0, 0, 0, 0), -1, -1));
        RMtabbedPane.addTab("Miesiac", MiesiacPanel);
        final JScrollPane scrollPane1 = new JScrollPane();
        scrollPane1.setHorizontalScrollBarPolicy(30);
        scrollPane1.setVerticalScrollBarPolicy(20);
        MiesiacPanel.add(scrollPane1, new com.intellij.uiDesigner.core.GridConstraints(1, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, null, null, null, 0, false));
        MiesiacPoprzedni = new JList();
        MiesiacPoprzedni.setLayoutOrientation(0);
        MiesiacPoprzedni.setToolTipText("");
        scrollPane1.setViewportView(MiesiacPoprzedni);
        MiesiacPNazwa = new JLabel();
        MiesiacPNazwa.setHorizontalAlignment(10);
        MiesiacPNazwa.setText("");
        MiesiacPanel.add(MiesiacPNazwa, new com.intellij.uiDesigner.core.GridConstraints(0, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_NORTHWEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JScrollPane scrollPane2 = new JScrollPane();
        scrollPane2.setHorizontalScrollBarPolicy(30);
        scrollPane2.setVerticalScrollBarPolicy(20);
        MiesiacPanel.add(scrollPane2, new com.intellij.uiDesigner.core.GridConstraints(1, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, null, null, null, 0, false));
        MiesiacWybrany = new JList();
        MiesiacWybrany.setLayoutOrientation(0);
        scrollPane2.setViewportView(MiesiacWybrany);
        MiesiacWNazwa = new JLabel();
        MiesiacWNazwa.setText("");
        MiesiacPanel.add(MiesiacWNazwa, new com.intellij.uiDesigner.core.GridConstraints(0, 1, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_NORTHWEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        final JScrollPane scrollPane3 = new JScrollPane();
        scrollPane3.setHorizontalScrollBarPolicy(30);
        scrollPane3.setVerticalScrollBarPolicy(20);
        MiesiacPanel.add(scrollPane3, new com.intellij.uiDesigner.core.GridConstraints(1, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_BOTH, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_CAN_SHRINK | com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, null, null, null, 0, false));
        MiesiacNastepny = new JList();
        MiesiacNastepny.setLayoutOrientation(0);
        scrollPane3.setViewportView(MiesiacNastepny);
        MiesiacNNazwa = new JLabel();
        MiesiacNNazwa.setText("");
        MiesiacPanel.add(MiesiacNNazwa, new com.intellij.uiDesigner.core.GridConstraints(0, 2, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_NORTHWEST, com.intellij.uiDesigner.core.GridConstraints.FILL_NONE, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, null, null, 0, false));
        MyToolBar = new JToolBar();
        MyToolBar.setRollover(false);
        MyToolBar.putClientProperty("JToolBar.isRollover", Boolean.FALSE);
        MainPanel.add(MyToolBar, new com.intellij.uiDesigner.core.GridConstraints(1, 0, 1, 1, com.intellij.uiDesigner.core.GridConstraints.ANCHOR_CENTER, com.intellij.uiDesigner.core.GridConstraints.FILL_HORIZONTAL, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_WANT_GROW, com.intellij.uiDesigner.core.GridConstraints.SIZEPOLICY_FIXED, null, new Dimension(-1, 20), null, 0, false));
        Dzis = new JButton();
        Dzis.setText("Dzień dziejszy");
        MyToolBar.add(Dzis);
        IdzDo = new JButton();
        IdzDo.setText("Idź do");
        MyToolBar.add(IdzDo);
        final JLabel label1 = new JLabel();
        label1.setText("Rok");
        MyToolBar.add(label1);
        Rokspinner = new JSpinner();
        Rokspinner.setMinimumSize(new Dimension(60, 28));
        MyToolBar.add(Rokspinner);
        final JLabel label2 = new JLabel();
        label2.setText("Miesiąc");
        MyToolBar.add(label2);
        MiesComb = new JComboBox();
        MyToolBar.add(MiesComb);
    }

    /**
     * @noinspection ALL
     */
    public JComponent $$$getRootComponent$$$() {
        return MainPanel;
    }
}


