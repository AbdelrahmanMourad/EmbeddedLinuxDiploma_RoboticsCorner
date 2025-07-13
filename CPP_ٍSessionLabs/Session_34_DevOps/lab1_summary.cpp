/*
========================================================================================================
DevOps - Section Notes
========================================================================================================
    • Standardized process (for Consistency):
        ○ Docker Container.
        ○ CI/CD Server to run the container.
        ○ Unify the build process (Tool-Chain) on all environments.
            - Docker File -> Docker Hub for all machines.
        ○ It can be scalable.


    • Agile Principles drive DevOps:
        ○ Early and continuous delivery of high-value sw.
        ○ Welcome on change.
        ○ Working SW is the primary method of tracking progress.
        ○ Continuous attention to achieving technical excellence and great design.
        ○ Developers and business leaders must collaborate daily.
        ○ Simplicity, or finding the value in saving workers from performing extra work.
        ○ Self-organized teams are the foundation for the best architectures, designs, and requirements.
        ○ Face-to-face communication are the most effective way to share information.
        ○ At routine intervals, teams reflect on how they can improve the product.


    • GoogleTest / CodeBeamer Xunit Uploader (used by BMW).

========================================================================================================
*/

/*
========================================================================================================
DevOps - From Basics to Containers & CI/CD Pipelines (Summary)
========================================================================================================
| What is DevOps?
| - DevOps is a set of practices that combines software development (Dev) and IT operations (Ops).
| - Its goal is to shorten the development lifecycle, increase deployment frequency, and deliver high-quality software.
| - DevOps emphasizes collaboration, automation, continuous integration, and continuous delivery (CI/CD).

--------------------------------------------------------------------------------
| Key DevOps Principles:
| - Collaboration between development and operations teams.
| - Automation of build, test, and deployment processes.
| - Continuous Integration (CI): Automatically build and test code on every commit.
| - Continuous Delivery/Deployment (CD): Automatically deliver or deploy code to production or staging.
| - Infrastructure as Code (IaC): Manage infrastructure using code (e.g., Docker, Terraform).
| - Monitoring and feedback loops for continuous improvement.

--------------------------------------------------------------------------------
| Containers (e.g., Docker):
| - Containers package applications and their dependencies into a single, portable unit.
| - Ensures consistency across development, testing, and production environments.
| - Dockerfile: Script to build a container image.
| - Docker Hub: Public/private registry to store and share container images.

--------------------------------------------------------------------------------
| Local CI/CD Pipeline (On-Premises Server):
| 1. Developer pushes code to version control (e.g., Git).
| 2. Local CI/CD server (e.g., Jenkins, GitLab Runner) detects changes.
| 3. Pipeline steps:
|    - Checkout code
|    - Build (compile, package)
|    - Run tests (unit, integration)
|    - Build Docker image
|    - Push image to local/private Docker registry
|    - Deploy to local server or test environment

--------------------------------------------------------------------------------
| Cloud CI/CD Pipelines (GitHub Actions / GitLab CI):
| - GitHub Actions and GitLab CI/CD provide cloud-based pipelines triggered by code changes.
| - Typical pipeline steps:
|    - Checkout code
|    - Build and test
|    - Build Docker image
|    - Push image to Docker Hub or GitLab Container Registry
|    - Deploy to cloud (e.g., AWS, Azure, GCP) or on-premises server

--------------------------------------------------------------------------------
| Example: GitHub Actions Workflow (YAML)
| name: CI/CD Pipeline
| on: [push]
| jobs:
|   build:
|     runs-on: ubuntu-latest
|     steps:
|       - uses: actions/checkout@v2
|       - name: Build Docker image
|         run: docker build -t myapp:latest .
|       - name: Run tests
|         run: docker run myapp:latest ./run_tests.sh
|       - name: Push to Docker Hub
|         run: docker push myapp:latest

--------------------------------------------------------------------------------
| Tips & Best Practices:
| - Use containers for consistency and portability.
| - Automate as much as possible (builds, tests, deployments).
| - Use version control for both code and infrastructure.
| - Monitor pipelines and deployments for quick feedback.
| - Secure secrets and credentials in CI/CD systems.
| - Start simple, iterate, and improve your pipeline over time.

--------------------------------------------------------------------------------
| Interview Q&A:
| Q1: What is DevOps and why is it important?
| Q2: What are containers and why use Docker?
| Q3: What is CI/CD and how does it benefit development?
| Q4: How do you set up a pipeline on GitHub/GitLab?
| Q5: What is the difference between local and cloud CI/CD?
| Q6: How do you ensure security in your pipeline?
========================================================================================================
*/