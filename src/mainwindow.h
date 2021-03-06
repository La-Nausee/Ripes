#pragma once

#include <QMainWindow>

#include "program.h"

QT_FORWARD_DECLARE_CLASS(QToolBar)
QT_FORWARD_DECLARE_CLASS(QStackedWidget)
QT_FORWARD_DECLARE_CLASS(QActionGroup)

namespace Ripes {

namespace Ui {
class MainWindow;
}

class EditTab;
class MemoryTab;
class ProcessorTab;
class ProcessorHandler;
struct LoadFileParams;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    void closeEvent(QCloseEvent* event) override;
    void fitToView();

private slots:
    void wiki();
    void version();

    void loadFileTriggered();

    void saveFilesTriggered();
    void saveFilesAsTriggered();
    void newProgramTriggered();

    void processorUpdated() { emit updateMemoryTab(); }

signals:
    void update();
    void updateMemoryTab();

private:
    void loadFile(const QString& filename, FileType type);

    void setupMenus();
    void setupExamplesMenu(QMenu* parent);

    Ui::MainWindow* m_ui = nullptr;
    QActionGroup* m_binaryStoreAction;
    QToolBar* m_toolbar = nullptr;

    bool m_hasSavedFile = false;

    // Tabs
    QStackedWidget* m_stackedTabs = nullptr;
    ProcessorTab* m_processorTab = nullptr;
    EditTab* m_editTab = nullptr;
    MemoryTab* m_memoryTab = nullptr;
};
}  // namespace Ripes
